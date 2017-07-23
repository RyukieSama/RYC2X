//
//  RedNode.hpp
//  redBox-mobile
//
//  Created by 王荣庆 on 2017/7/23.
//

#ifndef RedNode_hpp
#define RedNode_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class RedNode:public Node {
public:
    CREATE_FUNC(RedNode);
    virtual bool init();
    RedNode();//构造函数
    ~RedNode();//析构函数
    
public:
    void loadAnimation();
    void playAnimation();
    void aniCallBack();
    void setDefaultState();
    void addTitle(const char * text);
    
private:
    Animate * animate;
    Sprite * backImage;
    Label * title;
};

#endif /* RedNode_hpp */
