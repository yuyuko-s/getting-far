#include <fmt/format.h>
#include <Geode/modify/PlayLayer.hpp>
#include "../utils/Webhook.hpp";
#include <Geode/utils/web.hpp>
#include "../utils/Settings.hpp";

using namespace geode::prelude;

class $modify(GFPlayLayer, PlayLayer) {
	struct Fields {
		GJGameLevel* currentLevel;
		EventListener<web::WebTask> m_listener;
		int attemptStart;
	};

	bool init(GJGameLevel * level, bool p1, bool p2) {
		if (!PlayLayer::init(level, p1, p2)) return false;

		m_fields->currentLevel = level;
		log::info("Entering level {}", level->m_levelName);

		m_fields->attemptStart = this->getCurrentPercentInt();

		return true;
	}

	void resetLevel() {
		PlayLayer::resetLevel();

		m_fields->attemptStart = this->getCurrentPercentInt();

	}

	void destroyPlayer(PlayerObject * player, GameObject * p1) {
		PlayLayer::destroyPlayer(player, p1);
		if (!player->m_isDead) return;

		int deathPct = this->getCurrentPercentInt();

		int minPct = Settings::defaultPct();

		if (deathPct >= minPct) {
			reportResult();
		}
	}

	void levelComplete() {
		PlayLayer::levelComplete();
		reportResult();
	}

	void reportResult() {
		if (m_level->isPlatformer() || m_isPracticeMode || m_isTestMode) return;

		int deathPct = this->getCurrentPercentInt();
		auto levelName = m_fields->currentLevel->m_levelName;
		auto difficulty = m_fields->currentLevel->m_demonDifficulty;

		m_fields->m_listener.bind([](web::WebTask::Event* e) {
			if (web::WebResponse* res = e->getValue()) {
				log::debug("{}", res->string().unwrapOr("Uh oh!"));
			}
			});

		m_fields->m_listener.setFilter(Webhook::sendDeath(m_fields->currentLevel, deathPct));


		log::debug("Result reported\nLevelName={}\nDiff={}\ndeathPct={}\n", levelName, difficulty, deathPct);
	}
};

