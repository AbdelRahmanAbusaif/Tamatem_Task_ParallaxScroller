#include "JumpButton.h"

USING_NS_CC;

// Factory Pattern: Responsible for creating and initializing a JumpButton instance
JumpButton* JumpButton::createJumpButton(Character& character)
{
    JumpButton* button = new (std::nothrow) JumpButton();
    if (button && button->init(character))
    {
        button->autorelease();
        return button;
    }
    CC_SAFE_DELETE(button);
    return nullptr;
}

// Initialize the JumpButton with a reference to the Character instance
bool JumpButton::init(Character& character)
{
    if (!Node::init())
        return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    _character = &character;

    // Create a button using MenuItemImage
    auto jumpButton = MenuItemImage::create(
            "Sprite/UI/Jump Button.png",
            "Sprite/UI/Jump Button Clicked.png",
            [=](Ref* sender) {
                _character->playJumpAnimation();
            }
    );

    // Set the button's position
    jumpButton->setPosition(Vec2(visibleSize.width - origin.x - jumpButton->getContentSize().width / 2,
                                 visibleSize.height - origin.y - jumpButton->getContentSize().height / 2));

    // Set the button's scale
    auto menu = Menu::create(jumpButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    return true;
}
