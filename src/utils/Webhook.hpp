#include <Geode/utils/web.hpp>
using namespace geode::prelude;


class Webhook {
public:
	static web::WebTask sendDeath(GJGameLevel* currentLevel, int deathPct);
};