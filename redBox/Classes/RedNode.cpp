//
//  RedNode.cpp
//  redBox-mobile
//
//  Created by 王荣庆 on 2017/7/23.
//

#include "RedNode.hpp"

std::vector<std::string> contextRed = {"百万大奖", "五毛", "再来一次"};

bool RedNode::init() {
    if (!Node::init()) {
        return false;
    }
    
    backImage = Sprite::create("res/default.png");
    backImage->setAnchorPoint(Point::ZERO);//方便触摸点的坐标计算
    this->addChild(backImage);
    
    //设置红包contentSize和精灵一样大
    setContentSize(backImage->getContentSize());
    
    
    
    return true;
}

RedNode::RedNode() {
    //对成员变量进行初始赋值
    backImage = 0;
    animate = 0;
    title = 0;
}

RedNode::~RedNode() {
    backImage = 0;
    animate = 0;
    title = 0;
}

void RedNode::loadAnimation() {
    //加载动画资源   一般在加载页面做这个事
    SpriteFrameCache * spriteFrameCache = SpriteFrameCache::getInstance();
    int index = 1;
    
    SpriteFrame * frame = NULL;
    
    //容器  是COCOCS封装的
    Vector<SpriteFrame *> frameArray;
    
    do {
        frame = spriteFrameCache->getSpriteFrameByName(__String::createWithFormat("%d.png",index)->getCString());
        if (frame == 0) {
            break;
        } else {
            frameArray.pushBack(frame);
            index++;
        }
    } while (true);
    
    Animation * animation = Animation::createWithSpriteFrames(frameArray);
    animation->setLoops(1);//循环次数
    animation->setRestoreOriginalFrame(false);//是否在播放完成后恢复最初的样子
    animation->setDelayPerUnit(0.1);//帧间隔
    
    //通过animation创建animate
    animate = Animate::create(animation);
    //应为不需要立刻执行动画又不能被释放掉 这里需要retain一下  防止被释放掉
    //其他成员变量使用了   addChild 方法的对象都会被自动 retain的所以不需要自己写
    animate->retain();
}

void RedNode::playAnimation() {
    if (backImage == 0 || animate == 0) {
        return;
    }
    
    backImage->setAnchorPoint(Vec2(0.5, 0.5));//恢复锚点位置  为了动画
    
    CallFunc * callFunc = CallFunc::create(CC_CALLBACK_0(RedNode::aniCallBack, this));
    Sequence * seq = Sequence::create(animate, callFunc, NULL);
    backImage->runAction(seq);
    
}

void RedNode::aniCallBack() {
    //从容器中随机获取字符创
    std::string str = contextRed[std::rand()%contextRed.size()];//设置随机范围
    printf("%s",str.c_str());
    addTitle(str.c_str());
}

void RedNode::setDefaultState() {
    if (backImage != 0) {
        backImage->removeFromParent();
        backImage = Sprite::create("res/default.png");
        backImage->setPosition(Point::ZERO);
        this->addChild(backImage); //或者直接更换纹理
        
        if (title != 0) {
            title->setVisible(false);
        }
        
    }
}

void RedNode::addTitle(const char * text) {
    if (title != 0) {//非第一次点红包
        title->setString(text);
        title->setVisible(true);
        return;
    }
    
    title = Label::createWithSystemFont(text, "", 40);
    title->setPosition(Point::ZERO);
    title->setColor(Color3B::RED);
    this->addChild(title,1);
    return;
    
}
