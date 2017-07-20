//
//  OpenLayer.hpp
//  helloworld-mobile
//
//  Created by 王荣庆 on 2017/7/20.
//

#ifndef OpenLayer_hpp
#define OpenLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "SceneManager.hpp"

USING_NS_CC;

class OpenLayer : public Layer {
public:
    CREATE_FUNC(OpenLayer);
    virtual bool init();
    void onMenuClock(Ref * pSender);
public:
    SceneManager * tsm;
};

#endif /* OpenLayer_hpp */
