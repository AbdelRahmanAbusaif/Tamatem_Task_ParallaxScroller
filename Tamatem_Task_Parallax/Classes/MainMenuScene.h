#include "cocos2d.h"
#include "ParallaxManager.h"

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    cocos2d::Vector<cocos2d::Sprite *> backgroundLayer;
    cocos2d::Vector<cocos2d::Sprite *> midgroundLayer;
    cocos2d::Vector<cocos2d::Sprite *> foregroundLayer;

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);
private:
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

    ParallaxManager* parallaxNode;

    cocos2d::Vec2 lastTouchPos;
};
