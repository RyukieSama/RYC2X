#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "RedNode.hpp"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    //
    HelloWorld();
    ~HelloWorld();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void redNodeClick(Ref * pSender);
    
    void update(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    
public:
    void setBackground(const char * filename);
    
private:
    Sprite * backImage;
    RedNode * redNode;
    int state;
};

#endif // __HELLOWORLD_SCENE_H__
