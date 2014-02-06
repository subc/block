#include "GameScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* GameScene::scene()
{
    CCScene *scene = CCScene::create();
    GameScene *layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

    //背景色を指定
    if (!CCLayerColor::initWithColor(ccc4(51, 75, 112, 255))) {
        return false;
    }

    initForVariables();
    createBackground();

    // 1秒毎にupdateを呼ぶ
    this->scheduleUpdate();

    return true;
}

// 1秒毎に実行
void GameScene::update(float delta)
{
    if (rand()%100 > 10)
    {

    }
    CCLOG("%d", rand());
}

void GameScene::createBall(kTag tag, kBall type, CCPoint spawnPoint)
{
    BallSprite* ball = BallSprite::create(tag, type);
    ball->setPosition(spawnPoint);
    this->addChild(ball, kZOrderBall, tag);
}

// リソースを生成
void GameScene::initForVariables()
{
}

// 初期描写
void GameScene::createBackground()
{
}

void GameScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
