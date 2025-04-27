#include "ParallaxManager.h"
#include "string"

USING_NS_CC;

// Factory Pattern: Responsible for creating and initializing a Parallax instance
ParallaxManager* ParallaxManager::createManager()
{
    ParallaxManager* manager = new (std::nothrow) ParallaxManager();
    if (manager && manager->init())
    {
        manager->autorelease();
        return manager;
    }
    CC_SAFE_DELETE(manager);
    return nullptr;
}

bool ParallaxManager::init()
{
    if (!ParallaxNode::init())
        return false;

    // Initialize the visible size and origin
    _visibleSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();

    return true;
}

void ParallaxManager::addInfiniteLayer(const std::string& fileName, const cocos2d::Vec2& ratio,cocos2d::Vector<cocos2d::Sprite *> &layerVector)
{
    // Declare a lambda function to create and configure the sprite
    // This function will create a sprite, set its name, content size, and position
    // The lambda function captures the fileName and ratio by reference
    auto createAndConfigureSprite = [&](const std::string &nameSuffix, float positionX) -> Sprite* {
        auto sprite = Sprite::create(fileName);
        sprite->setName(fileName + nameSuffix);
        sprite->setContentSize(_visibleSize);
        sprite->setPositionX(positionX);
        return sprite;
    };

    // Create the sprite using the lambda function
    auto sprite1 = createAndConfigureSprite("1", _visibleSize.width / 2 + _origin.x);
    auto sprite2 = createAndConfigureSprite("2", _visibleSize.width / 2 + _origin.x + sprite1->getContentSize().width);
    auto sprite3 = createAndConfigureSprite("3", _visibleSize.width / 2 + _origin.x - sprite1->getContentSize().width);

    float width = sprite1->getContentSize().width;

    addChild(sprite1, 1, ratio, Vec2(_visibleSize.width / 2 + _origin.x, _visibleSize.height / 2 + _origin.y));
    addChild(sprite2, 1, ratio, Vec2(_visibleSize.width / 2 + _origin.x + width, _visibleSize.height / 2 + _origin.y));
    addChild(sprite3, 1, ratio, Vec2(_visibleSize.width / 2 + _origin.x - width, _visibleSize.height / 2 + _origin.y));

    layerVector.pushBack(sprite1);
    layerVector.pushBack(sprite2);
    layerVector.pushBack(sprite3);
}
