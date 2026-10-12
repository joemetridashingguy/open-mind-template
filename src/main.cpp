
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(AILearningMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto menu = this->getChildByID("bottom-menu");
        if (!menu) {
            log::warn("AI Learning Mod: bottom-menu not found");
            return true;
        }

        auto sprite = CCSprite::createWithSpriteFrameName(
            "GJ_likeBtn_001.png"
        );

        if (!sprite) {
            sprite = CCSprite::create();
        }

        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(AILearningMenu::onAILearning)
        );

        button->setID("ai-learning-button"_spr);
        menu->addChild(button);
        menu->updateLayout();

        log::info("AI Learning Mod loaded!");
        return true;
    }

    void onAILearning(CCObject*) {
        FLAlertLayer::create(
            "AI Learning Mod",
            "Status: Prototype\n\n"
            "Next goals:\n"
            "- XDBot recording support\n"
            "- Recorded-run analysis\n"
            "- Experimental playback tools",
            "OK"
        )->show();
    }
};
