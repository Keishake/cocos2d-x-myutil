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
#include <extensions/cocos-ext.h>

class ___FILEBASENAME___ : public cocos2d::LayerColor, public cocos2d::extension::TableViewDataSource, public cocos2d::extension::TableViewDelegate
{
public:
    ___FILEBASENAME___();
    virtual ~___FILEBASENAME___();
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(___FILEBASENAME___);

    //TableViewDataSourceの抽象メソッド
    virtual cocos2d::Size cellSizeForTable(cocos2d::extension::TableView* table);
    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView* table,ssize_t idx);
    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView* table);

    //TableViewDelegateの抽象メソッド
    virtual void tableCellTouched(cocos2d::extension::TableView* table,cocos2d::extension::TableViewCell* cell);

    //TableViewDelegateが継承しているScrollViewの抽象メソッド
    virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view){};
    virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view){};

protected:

private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Vec2 center;

    CC_SYNTHESIZE_RETAIN(cocos2d::extension::TableView*, m_tableView, TableView);

};

#endif /* defined(_____PROJECTNAMEASIDENTIFIER________FILEBASENAMEASIDENTIFIER_____) */
