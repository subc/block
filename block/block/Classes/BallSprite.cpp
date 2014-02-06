#include "BallSprite.h"

using namespace cocos2d;

BallSprite::BallSprite()
{
}

BallSprite::~BallSprite()
{
}

BallSprite* BallSprite::create(int tag, kBall type)
{
    BallSprite* ret = new BallSprite();
    
    if (ret && ret->init(tag, type))
    {
        return ret;
        
    } else {
        CC_SAFE_DELETE(ret);
        return NULL;
    }
}

bool BallSprite::init(int tag, kBall type)
{
    if (!CCSprite::initWithFile(getImageFileName(type)))
    {
        return false;
    }
    
    setTag(tag);
    setType(type);
    
    return true;
}

const char* BallSprite::getImageFileName(kBall type)
{
    switch (type) {
        case kBall01:
            return "ball.png";
            
        case kBall02:
            return "ball.png";
            
        case kBall03:
            return "ball.png";
            
        case kBall04:
            return "ball.png";
            
        default:
            CCAssert(false, "invalid BallType");
            return "";
    }
}