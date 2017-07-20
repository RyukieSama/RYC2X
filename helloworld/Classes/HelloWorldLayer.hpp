//
//  HelloWorldLayer.hpp
//  helloworld-mobile
//
//  Created by 王荣庆 on 2017/7/20.
//

#ifndef HelloWorldLayer_hpp
#define HelloWorldLayer_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;//添加命名空间

class HelloWorldLayer : public Layer {
    
public:
//    CREATE_FUNC(HelloWorldLayer);
    static HelloWorldLayer * create();//声明
    virtual bool init();
    void menuCloseCallBack(Ref * pSender);
    
};

#endif /* HelloWorldLayer_hpp */
