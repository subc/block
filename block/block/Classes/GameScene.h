#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Config.h"
#include "BallSprite.h"


class GameScene : public cocos2d::CCLayerColor
{
public:
    GameScene();
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(GameScene);

private:
    CCSize    winSize;
    int       score;
    void initForVariables();
    void createBackground();
    void createBall(kTag tag, kBall type, CCPoint spawnPoint);
    void update(float delta);
};

#endif // __GAME_SCENE_H__
