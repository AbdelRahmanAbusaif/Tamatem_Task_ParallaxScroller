#include "MainMenuScene.h"
#include "Character.h"
#include "ParallaxManager.h"
#include "JumpButton.h"
#include "Firefly.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

bool MainMenuScene::init()
{
    if (!Scene::init())
        return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto sizeOfForegroundItem = visibleSize / 4 ;

    // declare ParallaxNode and initialize it with multiple layers
    parallaxNode = ParallaxManager::createManager();
    parallaxNode->addInfiniteLayer("Sprite/Background/1.png", Vec2(0.1f, 0),backgroundLayer,visibleSize.width/2,visibleSize);
    parallaxNode->addInfiniteLayer("Sprite/Background/2.png", Vec2(0.2f, 0),backgroundLayer,visibleSize.width/2,visibleSize);

    parallaxNode->addInfiniteLayer("Sprite/Background/3.png", Vec2(0.3f, 0),midgroundLayer,visibleSize.width/2,visibleSize);
    parallaxNode->addInfiniteLayer("Sprite/Background/4.png", Vec2(0.5f, 0),midgroundLayer,visibleSize.width/2,visibleSize);
    parallaxNode->addInfiniteLayer("Sprite/Background/5.png", Vec2(0.6f, 0),midgroundLayer,visibleSize.width/2,visibleSize);

    parallaxNode->addInfiniteLayer(("Sprite/Foreground/Rock1.PNG"), Vec2(0.7f, 0),foregroundLayer,visibleSize.width, sizeOfForegroundItem);
    parallaxNode->addInfiniteLayer(("Sprite/Foreground/Rock2.PNG"), Vec2(0.7f, 0),foregroundLayer,visibleSize.width/2, sizeOfForegroundItem / 2 );
    parallaxNode->addInfiniteLayer(("Sprite/Foreground/Rock3.PNG"), Vec2(0.75f, 0),foregroundLayer,visibleSize.width/8, sizeOfForegroundItem / 2 );

    parallaxNode->addInfiniteLayer(("Sprite/Foreground/Grass1.png"), Vec2(0.75f, 0),foregroundLayer,visibleSize.width/2, visibleSize );
    parallaxNode->addInfiniteLayer(("Sprite/Foreground/Grass2.png"), Vec2(0.75f, 0),foregroundLayer,visibleSize.width/2, visibleSize );

    addChild(parallaxNode);

    auto character = Character::createCharacter();

    // 500 is the z-order of the character, you can change it to make it appear in front or behind other layers (You can put 2 or 3 but im use 500 to make it appear in front of the background)
    addChild(character,500);

    auto jumpButton = JumpButton::createJumpButton(*character);
    addChild(jumpButton);

    auto firefly = Firefly::createFireFly();
    addChild(firefly, 1000); // 1000 is the z-order of the firefly, you can change it to make it appear in front or behind other layers

    // Enable touch events
    // This is a simple touch listener that will allow you to move the background
    // It uses the EventListenerTouchOneByOne class to handle touch events
    // The onTouchBegan method is called when a touch begins, and the onTouchMoved method is called when the touch moves
    // The touch listener is added to the event dispatcher, which will call the appropriate methods when a touch event occurs
    // The touch listener is set to swallow touches, which means that it will consume the touch event and prevent it from being passed to other nodes
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