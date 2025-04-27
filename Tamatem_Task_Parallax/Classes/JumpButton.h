#pragma once

#include "cocos2d.h"
#include "Character.h"

class JumpButton : public cocos2d::Node
{
public:
    static JumpButton* createJumpButton(Character& character);
    bool init(Character& character);

private:
    Character* _character;
};
