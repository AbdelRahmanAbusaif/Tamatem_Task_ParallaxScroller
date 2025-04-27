#pragma once

#include "cocos2d.h"

class Character : public cocos2d::Sprite
{
public:
    static Character* createCharacter();
    bool init() override;

    void playIdleAnimation();
    void playJumpAnimation();
    bool isJumping() const { return _isJumping; }

private:
    bool _isJumping = false;
};
