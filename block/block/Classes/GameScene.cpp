#include "GameScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

GameScene::GameScene()
:winSize(CCDirector::sharedDirector()->getWinSize())
,score(0)
{
//    srand((unsigned)time(NULL));
}

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

// フレーム毎に実行
void GameScene::update(float delta)
{
    if (rand()%100 > 95)
    {
        createBall(kTagBall, kBall01, ccp(winSize.width - 200, winSize.height - 200));
        CCLOG("create kBall01");
    }
}

void GameScene::createBall(kTag tag, kBall type, CCPoint spawnPoint)
{
    BallSprite* ball = BallSprite::create(tag, type);
    ball->setPosition(spawnPoint);
    this->addChild(ball, kZOrderBall, tag);

    CCAction* action = CCMoveTo::create(1.0f, ccp(ball->getPositionX() - 700, ball->getPositionY() - rand()%200 ));
    ball->runAction(action);
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
