#include <fmt/format.h>
#include <Geode/modify/PlayLayer.hpp>
#include "../utils/Webhook.hpp";
#include <Geode/utils/web.hpp>

using namespace geode::prelude;

class $modify(GFPlayLayer, PlayLayer) {
	struct Fields {
		GJGameLevel* currentLevel;
		EventListener<web::WebTask> m_listener;
	};

	bool init(GJGameLevel * level, bool p1, bool p2) {
		if (!PlayLayer::init(level, p1, p2)) return false;

		m_fields->currentLevel = level;
		log::info("Entering level {}", level->m_levelName);

		return true;
	}

	void destroyPlayer(PlayerObject * player, GameObject * p1) {
		PlayLayer::destroyPlayer(player, p1);
		if (!player->m_isDead) return;

		if (m_level->isPlatformer() || m_isPracticeMode) return;

		auto levelName = m_fields->currentLevel->m_levelName;
		auto difficulty = m_fields->currentLevel->m_demonDifficulty;

		auto deathPct = this->getCurrentPercentInt();

		if (deathPct > 0) {
			// do stuff
			m_fields->m_listener.bind([](web::WebTask::Event* e) {
				if (web::WebResponse* res = e->getValue()) {
					log::info("{}", res->string().unwrapOr("Uh oh!"));
				}
			});
			
			m_fields->m_listener.setFilter(Webhook::sendDeath());
			

			log::info("LevelName={}\nDiff={}\ndeathPct={}\n", levelName, difficulty, deathPct);
		}
	}
};