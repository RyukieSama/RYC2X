//
//  LoadLayer.hpp
//  helloworld-mobile
//
//  Created by 王荣庆 on 2017/7/20.
//

#ifndef LoadLayer_hpp
#define LoadLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "SceneManager.hpp"

USING_NS_CC;

class LoadLayer : public Layer {
public:
    CREATE_FUNC(LoadLayer);
    virtual bool init();
    
public:
    SceneManager * tsm;
};

#endif /* LoadLayer_hpp */
