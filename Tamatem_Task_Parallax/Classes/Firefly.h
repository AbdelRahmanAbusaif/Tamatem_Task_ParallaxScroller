#pragma once

#include "cocos2d.h"

class Firefly : public cocos2d::ParticleSystemQuad
{
public:
    static Firefly* createFireFly();
    bool init() override;

private:
    void playParticleAnimation();
};
