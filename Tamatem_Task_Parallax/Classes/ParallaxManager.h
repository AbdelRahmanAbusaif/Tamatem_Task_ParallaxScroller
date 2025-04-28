#pragma once

#include "cocos2d.h"

class ParallaxManager : public cocos2d::ParallaxNode
{
public:
    static ParallaxManager* createManager();
    bool init() override;

    void addInfiniteLayer(const std::string& fileName, const cocos2d::Vec2& ratio,cocos2d::Vector<cocos2d::Sprite *>& layerVector, const float positionX, const cocos2d::Size& imageSize);

private:
    cocos2d::Size _visibleSize;
    cocos2d::Vec2 _origin;
};
