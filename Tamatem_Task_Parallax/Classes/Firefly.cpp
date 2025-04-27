#include "Firefly.h"

USING_NS_CC;

// Factory Pattern: Responsible for creating and initializing a Firefly instance
Firefly* Firefly::createFireFly()
{
    Firefly* firefly = new (std::nothrow) Firefly();
    if (firefly && firefly->init())
    {
        firefly->autorelease();
        return firefly;
    }
    CC_SAFE_DELETE(firefly);
    return nullptr;
}

bool Firefly::init()
{
    if (!ParticleSystemQuad::initWithFile("Sprite/Particle/Firefly.png"))
        return false;

    playParticleAnimation();
    return true;
}

void Firefly::playParticleAnimation()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Create a particle system
    auto firefly = ParticleSystemQuad::create();

    firefly->setTexture(Director::getInstance()->getTextureCache()->addImage("Sprite/Particle/Firefly.png"));

    // Particle settings
    firefly->setDuration(ParticleSystem::DURATION_INFINITY); // Loop forever
    firefly->setEmissionRate(5);

    firefly->setLife(5.0f);  // Each firefly lives 5 seconds
    firefly->setLifeVar(2.0f); // Randomness

    firefly->setStartSize(10.0f);
    firefly->setStartSizeVar(5.0f);

    firefly->setEndSize(ParticleSystem::START_SIZE_EQUAL_TO_END_SIZE);

    firefly->setStartColor(Color4F(0.8f, 1.0f, 0.3f, 1.0f)); // Yellow-Green glow
    firefly->setEndColor(Color4F(0.8f, 1.0f, 0.3f, 0.0f));   // Fade to transparent

    firefly->setSpeed(20.0f); // Slow movement
    firefly->setSpeedVar(10.0f);

    firefly->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2)); // Centered or anywhere you want
    firefly->setPosVar(Vec2(visibleSize.width/2, visibleSize.height/2)); // They appear in a big area

    // Gravity to make them float more naturally
    firefly->setGravity(Vec2(0, 5));

    // Add to the scene
    this->addChild(firefly);
}