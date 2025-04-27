#include "MainMenuScene.h"
#include "Character.h"
#include "ParallaxManager.h"
#include "JumpButton.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

bool MainMenuScene::init()
{
    if (!Scene::init())
        return false;

    parallaxNode = ParallaxManager::createManager();
    parallaxNode->addInfiniteLayer("Sprite/Background/1.png", Vec2(0.1f, 0),backgroundLayer);
    parallaxNode->addInfiniteLayer("Sprite/Background/2.png", Vec2(0.2f, 0),backgroundLayer);

    parallaxNode->addInfiniteLayer("Sprite/Background/3.png", Vec2(0.3f, 0),midgroundLayer);

    parallaxNode->addInfiniteLayer("Sprite/Background/4.png", Vec2(0.5f, 0),foregroundLayer);
    parallaxNode->addInfiniteLayer("Sprite/Background/5.png", Vec2(0.6f, 0),foregroundLayer);

    addChild(parallaxNode);

    auto character = Character::createCharacter();
    addChild(character,500);

    auto jumpButton = JumpButton::createJumpButton(*character);
    addChild(jumpButton);

    // Enable touch events
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(MainMenuScene::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(MainMenuScene::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}
bool MainMenuScene::onTouchBegan(Touch* touch, Event* event)
{
    lastTouchPos = touch->getLocation();

    return true;
}

void MainMenuScene::onTouchMoved(Touch* touch, Event* event)
{
    Vec2 delta = touch->getDelta();
    Vec2 newPos = parallaxNode->getPosition() + Vec2(delta.x, 0);

    // update the position of the parallax node
    parallaxNode->setPosition(parallaxNode->getPosition() + Vec2(delta.x, 0));

    // Calculate the bounds
    float spriteWidth = backgroundLayer.at(0)->getContentSize().width;
    float maxRight = backgroundLayer.at(0)->getPositionX() + spriteWidth * 3 - 200; // Adjust this value as needed , the -200 is to make sure the background is not too close to the right side of the screen XD, Sorry but i don't have any assets to test with
    float maxLeft = backgroundLayer.at(0)->getPositionX() - spriteWidth * 3;

    // Clamp the new position within the bounds
    newPos.x = std::min(std::max(newPos.x, maxLeft), maxRight);

    // Update the last touch position
    lastTouchPos = touch->getLocation();
    // Update the parallax node position
    parallaxNode->setPosition(newPos);
}