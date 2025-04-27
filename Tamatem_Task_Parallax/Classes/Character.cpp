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

    this->setScale(2.0f);
    playIdleAnimation();
    return true;
}

void Character::playIdleAnimation()
{
    Vector<SpriteFrame*> idleFrames;

    for (int i = 0; i < 12; ++i)
    {
        std::string frameName = "Sprite/Character/idle-" + std::to_string(i) + ".png";
        auto frame = SpriteFrame::create(frameName, Rect(0, 0, this->getContentSize().width, this->getContentSize().height));
        frame->setAnchorPoint(Vec2(0.5f, 0.5f));
        idleFrames.pushBack(frame);
    }

    auto idleAnimation = Animation::createWithSpriteFrames(idleFrames, 0.2f);
    auto idleAnimate = RepeatForever::create(Animate::create(idleAnimation));
    idleAnimate->setTag(1);

    this->runAction(idleAnimate);
}

void Character::playJumpAnimation()
{
    if (_isJumping)
        return;

    _isJumping = true;
    this->stopAllActions();

    auto moveUp = MoveBy::create(0.2f, Vec2(0, 100));
    auto moveDown = MoveBy::create(0.2f, Vec2(0, -100));

    Vector<SpriteFrame*> jumpFrames;
    for (int i = 0; i < 7; ++i)
    {
        auto frameName = StringUtils::format("Sprite/Character/jump-%d.png", i);
        auto frame = SpriteFrame::create(frameName, Rect(0, 0, this->getContentSize().width, this->getContentSize().width));
        jumpFrames.pushBack(frame);
    }

    auto jumpAnimation = Animation::createWithSpriteFrames(jumpFrames, 0.1f);
    auto jumpAnimate = Animate::create(jumpAnimation);

    auto sequence = Sequence::create(
            jumpAnimate,
            CallFunc::create([this]() {
                playIdleAnimation();
                _isJumping = false;
            }),
            nullptr
    );

    this->runAction(Sequence::create(moveUp, moveDown, sequence));
}
