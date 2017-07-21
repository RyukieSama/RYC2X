//
//  OpenLayer.cpp
//  helloworld-mobile
//
//  Created by 王荣庆 on 2017/7/20.
//

#include "OpenLayer.hpp"

bool OpenLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    Label *label = Label::createWithSystemFont("Clock", "", 48);
    label->setPosition(Vec2(winSize.width/2, winSize.height*3/4));
    label->setColor(Color3B(255, 0, 0));
    this->addChild(label);
    
    MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont("Start", "", 30), CC_CALLBACK_1(OpenLayer::onMenuClock, this));
    menuItem->setTag(101);
    menuItem->setPosition(Vec2(winSize.width/2, winSize.height*0.3));
    
    MenuItemLabel * menuItemT = MenuItemLabel::create(Label::createWithSystemFont("End", "", 30), CC_CALLBACK_1(OpenLayer::onMenuClock, this));
    menuItemT->setTag(102);
    menuItemT->setPosition(Vec2(winSize.width/2, winSize.height*0.15));
    
    Menu *menu = Menu::create(menuItem, menuItemT, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true;
}

void OpenLayer::onMenuClock(cocos2d::Ref *pSender) {
    switch (((MenuItem *)pSender)->getTag()) {
        case 101:{
            tsm->gotoClockScene();
        }
            break;
        case 102:{
            Director::getInstance()->end();
            exit(0);
        }
            break;
        default:
            break;
    }
    
}


