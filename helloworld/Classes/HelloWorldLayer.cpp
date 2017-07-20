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
    
    auto sp = Sprite::create("02.jpg");
    sp->setPosition(Vec2(size.width/2, size.height/2));
    this->addChild(sp);
    
    Label * lbRy = Label::create();
    lbRy->setString("RyukieSama");
    lbRy->setSystemFontSize(24);
    lbRy->setPosition(Vec2(size.width/2, size.height*3/4));
    this->addChild(lbRy);
    
    //可以实现的类    Menu    controlButton   GUI中的 Button
    
    /**
     创建按钮
     Creates a menu item with a normal,selected  and disabled image with a callable object.
     */
    auto closeItem = MenuItemImage::create("menu.jpg", "", "", CC_CALLBACK_1(HelloWorldLayer::menuCloseCallBack, this));
    closeItem->setPosition(Vec2(900, 100));
    
    auto menu = Menu::create(closeItem,NULL);//...可以添加多个子菜单
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    
    return true;
}

void HelloWorldLayer::menuCloseCallBack(cocos2d::Ref *pSender) {
//    log("MenuClicked");
    CCLOG("MenuClicked");
}
