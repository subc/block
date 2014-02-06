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
        CCLOG("floats: %f", winSize.width);

    }

    // tagでget
    CCObject* obj = NULL;
	CCARRAY_FOREACH(this->getChildren(), obj)
	{
        CCNode* child = dynamic_cast<CCNode*>(obj);
        if (child->getTag() == kTagBall)
        {
            BallSprite* ball = dynamic_cast<BallSprite*>(child);
            // 弾を反射
            if (ball->getPositionX() == 100) {
//                CCLOG("@floats: %f", winSize.width);
//                CCAction* action = CCMoveTo::create(1.0f, ccp((winSize.width - 200), ball->getPositionY() * 2 - (winSize.height - 200)));

                // 弾が倍速になる
//                float h = ball->getPositionY() * 2 - (winSize.height - 200);
//                CCAction* action = CCMoveTo::create(1.0f, ccp(960, h));
//                action->setTag(kActionTagBall);
//                ball->stopActionByTag(kActionTagBall);
//                ball->runAction(action);
                ball->stopActionByTag(kActionTagBall);
                float h = ball->getPositionY() * 2 - (winSize.height - 200);
                CCAction* action = ball->getActionByTag(kActionTagBall);
                action = CCMoveTo::create(0.5f, ccp(960, h));
                ball->runAction(action);

                CCLOG("@floats: %f", h);

            }

            // 画面外の弾をremove
            if (ball->getPositionX() < 0) {
                ball->removeFromParentAndCleanup(true);
                CCLOG("remove kBall01");
            }
        }
    }

}

void GameScene::createBall(kTag tag, kBall type, CCPoint spawnPoint)
{
    BallSprite* ball = BallSprite::create(tag, type);
    ball->setPosition(spawnPoint);
    this->addChild(ball, kZOrderBall, tag);

    CCAction* action = CCMoveTo::create(1.0f, ccp(100, ball->getPositionY() - rand()%500 ));
    action->setTag(kActionTagBall);
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
