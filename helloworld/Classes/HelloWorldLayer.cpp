//
//  HelloWorldLayer.cpp
//  helloworld-mobile
//
//  Created by 王荣庆 on 2017/7/20.
//

#include "HelloWorldLayer.hpp"
HelloWorldLayer * HelloWorldLayer::create() {
    HelloWorldLayer *pRet = new HelloWorldLayer();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    } else {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool HelloWorldLayer::init() {
    
    if (!Layer::init()) {//习惯
        return false;
    }
    
    Size size = Director::getInstance()->getVisibleSize();
//    Label * lbRy = Label::createWithTTF("RyukieSama", "fonts/Marker Felt.ttf", 24);
    Label * lbRy = Label::create();
    lbRy->setString("RyukieSama");
    lbRy->setSystemFontSize(24);
    lbRy->setPosition(Vec2(size.width/2, size.height*3/4));
    this->addChild(lbRy);
    
    
    return true;
}
