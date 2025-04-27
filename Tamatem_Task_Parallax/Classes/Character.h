#pragma once

#include "cocos2d.h"

class Character : public cocos2d::Sprite
{
public:
    static Character* createCharacter();
    bool init() override;

    void  playIdleAnimation();
    void  playJumpAnimation();
private:
    bool _isJumping = false;
};
