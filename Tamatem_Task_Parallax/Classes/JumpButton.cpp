#include "JumpButton.h"

USING_NS_CC;

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

bool JumpButton::init(Character& character)
{
    if (!Node::init())
        return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    _character = &character;

    auto jumpButton = MenuItemImage::create(
            "Sprite/UI/Jump Button.png",
            "Sprite/UI/Jump Button Clicked.png",
            [=](Ref* sender) {
                _character->playJumpAnimation();
            }
    );

    jumpButton->setPosition(Vec2(visibleSize.width - origin.x - jumpButton->getContentSize().width / 2,
                                 visibleSize.height - origin.y - jumpButton->getContentSize().height / 2));

    auto menu = Menu::create(jumpButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    return true;
}
