//
//  LoadLayer.cpp
//  helloworld-mobile
//
//  Created by 王荣庆 on 2017/7/20.
//

#include "LoadLayer.hpp"

bool LoadLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Label *label = Label::create();
    label->setString("RyukieSama");
    label->setSystemFontSize(32);
    label->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(label);
    
    scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 2.0);
    
    return true;
}

void LoadLayer::onScheduleOnce(float dt) {
    tsm->gotoOpenScene();
    
    
}
