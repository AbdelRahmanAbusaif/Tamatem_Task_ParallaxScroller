#include "ParallaxManager.h"
#include "string"

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

    _visibleSize = Director::getInstance()->getVisibleSize();
    _origin = Director::getInstance()->getVisibleOrigin();

    return true;
}

void ParallaxManager::addInfiniteLayer(const std::string& fileName, const cocos2d::Vec2& ratio)
{
    auto sprite1 = Sprite::create(fileName);
    auto sprite2 = Sprite::create(fileName);
    auto sprite3 = Sprite::create(fileName);

    float width = sprite1->getContentSize().width;

    addChild(sprite1, 1, ratio, Vec2(_visibleSize.width / 2 + _origin.x, _visibleSize.height / 2 + _origin.y));
    addChild(sprite2, 1, ratio, Vec2(_visibleSize.width / 2 + _origin.x + width, _visibleSize.height / 2 + _origin.y));
    addChild(sprite3, 1, ratio, Vec2(_visibleSize.width / 2 + _origin.x - width, _visibleSize.height / 2 + _origin.y));
}
