//
//  ___FILENAME___
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//___COPYRIGHT___
//

#include "___FILEBASENAME___.h"

USING_NS_CC;
using namespace std;
using namespace extension;

___FILEBASENAME___::___FILEBASENAME___()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    center = Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);

}

___FILEBASENAME___::~___FILEBASENAME___()
{

}

Scene* ___FILEBASENAME___::createScene()
{
    auto scene = Scene::create();
    auto layer = ___FILEBASENAME___::create();
    scene->addChild(layer);
    return scene;
}

bool ___FILEBASENAME___::init()
{
    if (!LayerColor::init()) {
        return false;
    }

    m_tableView = TableView::create(this, Size(Vec2(visibleSize.width+origin.x, visibleSize.height+origin.y)));
    m_tableView->setDirection(TableView::Direction::VERTICAL);
    m_tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
    m_tableView->setDelegate(this);
    addChild(m_tableView);
    m_tableView->reloadData();

    return true;
}

// セルの大きさを設定する
Size ___FILEBASENAME___::cellSizeForTable(TableView *table){
    auto winSize = Director::getInstance()->getWinSize();
    return Size(winSize.width, 100);
}

// 1セルに表示させるValueをセット
TableViewCell* ___FILEBASENAME___::tableCellAtIndex(TableView *table, ssize_t idx){
    TableViewCell *cell = (TableViewCell*)table->dequeueCell();
    if (cell==nullptr) {
        cell = new TableViewCell();
        cell->autorelease();
    }
    // Edit cell here
    return cell;
}

// セル数
ssize_t ___FILEBASENAME___::numberOfCellsInTableView(TableView *table){
    return 0;
}

// セルがタッチされた時のcallback
void ___FILEBASENAME___::tableCellTouched(TableView* table, TableViewCell* cell){
    ssize_t index = cell->getIdx();
}

