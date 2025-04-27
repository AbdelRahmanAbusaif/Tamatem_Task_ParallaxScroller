#include "cocos2d.h"
#include "ParallaxManager.h"

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // These vectors will hold the layers for the parallax effect
    // They are used to manage the background, midground, and foreground layers
    // The layers are stored in vectors to allow for dynamic resizing and easy access
    // The layers made for make the parallax effect infinite, but you can use them for other purposes too (like what i did XD)
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
