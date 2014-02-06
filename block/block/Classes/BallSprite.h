#ifndef __block__BallSprite__
#define __block__BallSprite__

#include "cocos2d.h"
#include "Config.h"

using namespace cocos2d;

enum kBall {
    kBall01,
    kBall02,
    kBall03,
    kBall04
};

class BallSprite : public cocos2d::CCSprite
{
public:
    CC_SYNTHESIZE(int, tag, Tag);
    CC_SYNTHESIZE(kBall, type, Type);
    
    BallSprite();
    virtual ~BallSprite();
    virtual bool init(int tag, kBall type);
    static BallSprite* create(int tag, kBall type);
    
    void executeAction(CCSize winSize);
    
private:
	const char* getImageFileName(kBall type);
};

#endif /* defined(__block__BallSprite__) */