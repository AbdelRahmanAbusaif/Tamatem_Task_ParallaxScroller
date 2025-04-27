#include "SplashScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    return SplashScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("Sprite/SplashScene/Logo.png");
    if (background == nullptr)
    {
        problemLoading("'Sprite/SplashScene/Logo.png'");
    }
    else
    {
        background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        background->setContentSize(visibleSize);
        this->addChild(background, 0);
    }

    schedule(CC_SCHEDULE_SELECTOR(SplashScene::GoToMainMenu), 2.0f);

    return true;
}
void SplashScene::GoToMainMenu(float dt)
{
    auto scene = MainMenuScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}

