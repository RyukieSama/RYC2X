//
//  ClockLayer.hpp
//  helloworld-mobile
//
//  Created by 王荣庆 on 2017/7/20.
//

#ifndef ClockLayer_hpp
#define ClockLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "SceneManager.hpp"

USING_NS_CC;

class ClockLayer : public Layer {
public:
    CREATE_FUNC(ClockLayer);
    virtual bool init();
    
public:
    SceneManager * tsm;
};

#endif /* ClockLayer_hpp */
