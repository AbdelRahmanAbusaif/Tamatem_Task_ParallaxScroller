#include "Character.h"

USING_NS_CC;

Character* Character::createCharacter()
{
    Character* character = new (std::nothrow) Character();
    if (character && character->init())
    {
        character->autorelease();
        return character;
    }
    CC_SAFE_DELETE(character);
    return nullptr;
}

bool Character::init()
{
    if (!Sprite::initWithFile("Sprite/Character/idle-0.png"))
        return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    this->setScale(2.0f);
    this->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));

    playIdleAnimation();
    return true;
}

void Character::playIdleAnimation()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    this->create("Sprite/Character/idle-0.png");
    this->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));

    Vector<SpriteFrame*> idleFrames;

    for (int i = 0; i < 12; ++i)
    {
        std::string frameName = "Sprite/Character/idle-" + std::to_string(i) + ".png";
        auto frame = SpriteFrame::create(frameName, Rect(0, 0, this->getContentSize().width, this->getContentSize().height));
        frame->setAnchorPoint(Vec2(0.5f, 0.5f));
        idleFrames.pushBack(frame);
    }

    auto idleAnimation = Animation::createWithSpriteFrames(idleFrames, 0.1f);
    auto idleAnimate = RepeatForever::create(Animate::create(idleAnimation));
    idleAnimate->setTag(1);

    this->runAction(idleAnimate);
}

void Character::playJumpAnimation()
{
    if (_isJumping)
        return;

    this->stopAllActions();
    _isJumping = true;

    auto moveUp = MoveBy::create(0.3f, Vec2(0, 200));
    auto moveDown = MoveBy::create(0.3f, Vec2(0, -200));

    this->runAction(Sequence::create(
            moveUp,
            moveDown,
            nullptr
    ));

    Vector<SpriteFrame*> jumpFrames;
    for (int i = 0; i < 9; ++i)
    {
        std::string frameName = StringUtils::format("Sprite/Character/jump-%d.png", i);

        CCLOG("Width and High value : %f %f", this->getContentSize().width, this->getContentSize().height);
        auto frame = SpriteFrame::create(frameName, Rect(0, 0, this->getContentSize().width, this->getContentSize().width));
        frame->setAnchorPoint(Vec2(0.5f, 0.5f));
        jumpFrames.pushBack(frame);
    }

    auto jumpAnimation = Animation::createWithSpriteFrames(jumpFrames, 0.1f);
    auto jumpAnimate = Animate::create(jumpAnimation);
    jumpAnimate->setTag(2);

    this->runAction(Sequence::create(
            jumpAnimate,
            CallFunc::create([this]() {
                playIdleAnimation();
                _isJumping = false;
            }),
            nullptr
    ));
}
