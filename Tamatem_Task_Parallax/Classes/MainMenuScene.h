#include "cocos2d.h"
#include "ParallaxManager.h"

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);


private:
    void onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

    cocos2d::PrallaxManager* parallaxNode;

    cocos2d::Vec2 lastTouchPos;
};
