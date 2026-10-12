
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
            log::warn("AI Learning: bottom menu not found");
            return true;
        }

        // Use a text-based button instead of relying on an icon.
        auto sprite = ButtonSprite::create(
            "AI",
            "goldFont.fnt",
            "GJ_button_01.png",
            0.8f
        );

        if (!sprite) {
            log::warn("AI Learning: button sprite creation failed");
            return true;
        }

        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(AILearningMenu::onAILearning)
        );

        if (!button) {
            log::warn("AI Learning: button creation failed");
            return true;
        }

        button->setID("ai-learning-button"_spr);
        menu->addChild(button);
        menu->updateLayout();

        log::info("AI Learning initialized");
        return true;
    }

    void onAILearning(CCObject*) {
        FLAlertLayer::create(
            "AI Learning",
            "<cy>EXPERIMENTAL PROTOTYPE</c>\n\n"
            "<cg>MENU</c>\n"
            "Status: Ready\n\n"
            "<cy>RECORDING ANALYSIS</c>\n"
            "Status: Planned\n\n"
            "<cy>LEARNING ENGINE</c>\n"
            "Status: Planned\n\n"
            "<cy>XDBOT INTEGRATION</c>\n"
            "Status: Not connected\n\n"
            "<co>NEXT DEVELOPMENT STEPS</c>\n"
            "1. Import recorded attempts\n"
            "2. Analyze gameplay data\n"
            "3. Test playback integration\n\n"
            "Only the interface is implemented so far.",
            "CLOSE"
        )->show();
    }
};
