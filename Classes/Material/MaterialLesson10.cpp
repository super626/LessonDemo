#include "MaterialLesson10.h"

USING_NS_CC;

Scene* MaterialLesson10::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MaterialLesson10::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void setMaterial(Node* root, Material* material)
{
    auto sprite = dynamic_cast<Sprite3D*>(root);
    if (sprite)
    {
        sprite->setMaterial(material);
    }
    auto children = root->getChildren();
    for (auto child : children) {
        setMaterial(child, material);
    }
}

// on "init" you need to initialize your instance
bool MaterialLesson10::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MaterialLesson10::menuCloseCallback, this));
    
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

    // add "MathLesson1" splash screen"
    
    //create Sprite3D
    std::string filename = "res/Material/feijiku01.c3t";
    auto sprite = Sprite3D::create(filename);
    sprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/10 + origin.y);
    addChild(sprite);
    auto material = Material::createWithFilename("res/Material/lightmap.material");
    setMaterial(sprite, material);
    
    return true;
}



void MaterialLesson10::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
