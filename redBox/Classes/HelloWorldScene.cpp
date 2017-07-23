#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

void HelloWorld::setBackground(const char *filename) {
    if (!backImage) {
        backImage = Sprite::create(filename);
        backImage->setAnchorPoint(Point::ZERO);
        backImage->setPosition(Point::ZERO);
        this->addChild(backImage);
    }
    //纹理
    backImage->setTexture(filename);
}

HelloWorld::HelloWorld() {
    backImage = 0;
}

HelloWorld::~HelloWorld() {
    
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    setBackground("res/BackGround.jpg");
    
    auto item = MenuItemFont::create("抢", CC_CALLBACK_1(HelloWorld::redNodeClick, this));
    item->setFontSizeObj(120);
    item->setColor(Color3B::RED);
    
    auto menuQ = Menu::create(item,NULL);
//    menuQ->setPosition(Vec2::ZERO);
    menuQ->setPosition(visibleSize/2);
    this->addChild(menuQ);
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
//    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
//
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);
//
//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(sprite, 0);
//
    
    
    redNode = RedNode::create();
    redNode->loadAnimation();
    redNode->setVisible(false);
    this->addChild(redNode);
    
//    scheduleUpdate();
    
    return true;
}


void HelloWorld::update(float dt) {
    static float time = 0;
    if (time > 1.0f) {
        time = 0;
    } else {
        time += dt;
    }
    
    //红包随机位置
    float pos_x = std::rand()%640;
    float pos_y = std::rand()%960;
    redNode->setVisible(true);
    redNode->setPosition(pos_x,pos_y);
}

void HelloWorld::redNodeClick(cocos2d::Ref *pSender) {
//    scheduleUpdate();
    schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update), 0.5);
    static_cast<Node *>(pSender)->setVisible(false);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
