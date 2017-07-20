//
//  SceneManager.hpp
//  helloworld-mobile
//
//  Created by 王荣庆 on 2017/7/20.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class SceneManager {
public:
    //场景1 加载
    Scene *loadScene;
    
    
    //场景2  开始
    Scene *openScene;
    
    //场景3  时钟
    Scene *clockScene;
    
    void createLoadScene();
    void gotoOpenScene();
    void gotoClockScene();
    
};


#endif /* SceneManager_hpp */
