//
//  ___FILENAME___
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//___COPYRIGHT___
//

#ifndef _____PROJECTNAMEASIDENTIFIER________FILEBASENAMEASIDENTIFIER_____
#define _____PROJECTNAMEASIDENTIFIER________FILEBASENAMEASIDENTIFIER_____

#include "cocos2d.h"

class ___FILEBASENAME___ : public cocos2d::___VARIABLE_cocos2DXv3b2Subclass:identifier___
{
public:
    ___FILEBASENAME___();
    virtual ~___FILEBASENAME___();
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(___FILEBASENAME___);

protected:

private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Vec2 center;

};

#endif /* defined(_____PROJECTNAMEASIDENTIFIER________FILEBASENAMEASIDENTIFIER_____) */
