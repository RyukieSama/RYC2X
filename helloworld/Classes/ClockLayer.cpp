//
//  ClockLayer.cpp
//  helloworld-mobile
//
//  Created by 王荣庆 on 2017/7/20.
//

#include "ClockLayer.hpp"

bool ClockLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    Size winSize = Director::getInstance()->getWinSize();
    MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont("Back", "", 30), CC_CALLBACK_1(ClockLayer::menuCallBack, this));
    menuItem->setPosition(Vec2(winSize.width*0.9, winSize.height*0.9));
    
    auto menu = Menu::create(menuItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    _background = Sprite::create("res/background.jpg");
    _background->setPosition(Vec2(winSize.width/2, winSize.height/2));
    _background->setScale(0.5);//缩放
    this->addChild(_background);//,123层级
    
    _second = Sprite::create("res/miao.png");
    _second->setPosition(Vec2(winSize.width/2, winSize.height/2));
    _second->setScale(0.3);
    _second->setAnchorPoint(Vec2(0.5, 0));
    this->addChild(_second);
    
    _minute = Sprite::create("res/fen.png");
    _minute->setPosition(Vec2(winSize.width/2, winSize.height/2));
    _minute->setScale(0.3);
    _minute->setAnchorPoint(Vec2(0.5, 0));
    this->addChild(_minute);
    
    _hour = Sprite::create("res/shi.png");
    _hour->setPosition(Vec2(winSize.width/2, winSize.height/2));
    _hour->setScale(0.3);
    _hour->setAnchorPoint(Vec2(0.5, 0));
    this->addChild(_hour);
    
    //获取当前系统时间
    struct timeval nowTimeval;
    gettimeofday(&nowTimeval, NULL);
    struct tm *tm;
    time_t time_sec;
    time_sec = nowTimeval.tv_sec;
    tm = localtime(&time_sec);
    
    CCLOG("H: %d, M: %d, S:%d",tm->tm_hour,tm->tm_min,tm->tm_hour);
    
    mRotation = tm->tm_min * 6;
    sRotation = tm->tm_sec * 6;
    
    if (tm->tm_hour > 12) {
        hRotation = (tm->tm_hour - 12) * 5 * 6 + (mRotation/72) * 6;
    } else {
        hRotation = (tm->tm_hour) * 5 * 6 + (mRotation/72) * 6;
    }
    
    _second->setRotation(sRotation);
    _minute->setRotation(mRotation);
    _hour->setRotation(hRotation);
    
    return true;
}

void ClockLayer::menuCallBack(cocos2d::Ref *pSender) {
    
}

void ClockLayer::timeUpdate(float dt) {
    
}
