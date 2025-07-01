#include "../hooks/GFLevelInfoLayer.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include "../layers/GFLevelOptionsPopup.hpp"

using namespace geode::prelude;

class $modify(GFLevelInfoLayer, LevelInfoLayer) {
    struct Fields {
        CCMenuItemSpriteExtra* btn = nullptr;
    };

    bool init(GJGameLevel* p0, bool p1) {
        if (!LevelInfoLayer::init(p0, p1)) return false;

        auto s = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
        auto s2 = CCSprite::createWithSpriteFrameName("square02b_001-uhd.png");
        s2->setPosition(s->getContentSize() / 2);
        s->addChild(s2);

        m_fields->btn = CCMenuItemSpriteExtra::create(
            s,
            nullptr,
            this,
            menu_selector(GFLevelInfoLayer::openGFLayer)
        );

        m_fields->btn->setID("gf-button");
        m_fields->btn->setZOrder(1);
        m_fields->btn->setVisible(true);
        auto leftMenu = getChildByID("left-side-menu");
        leftMenu->addChild(m_fields->btn);
        leftMenu->updateLayout();
    }

    void openGFLayer(CCObject*) {
        // open getting far per-level options layer
        auto gfPopup = GFLevelOptionsPopup::create();
        gfPopup->show();
    }
};

