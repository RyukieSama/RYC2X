//
//  SceneManager.cpp
//  helloworld-mobile
//
//  Created by 王荣庆 on 2017/7/20.
//

#include "SceneManager.hpp"
#include "LoadLayer.hpp"
#include "OpenLayer.hpp"
#include "ClockLayer.hpp"

void SceneManager::createLoadScene() {
    loadScene = Scene::create();
    LoadLayer *layer = LoadLayer::create();
    layer->tsm = this;
    loadScene->addChild(layer);
}

void SceneManager::gotoOpenScene(){
    openScene = Scene::create();
    OpenLayer *layer = OpenLayer::create();
    layer->tsm = this;
    openScene->addChild(layer);
    
    Director::getInstance()->replaceScene(openScene);
    
}

void SceneManager::gotoClockScene(){
    clockScene = Scene::create();
    ClockLayer *layer = ClockLayer::create();
    layer->tsm = this;
    clockScene->addChild(layer);
    
    Director::getInstance()->replaceScene(clockScene);
    
    
}
