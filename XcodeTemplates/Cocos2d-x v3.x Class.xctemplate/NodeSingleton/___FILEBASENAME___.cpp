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

static ___FILEBASENAME___ *m_instance = NULL;

___FILEBASENAME___::___FILEBASENAME___()
{

}

___FILEBASENAME___::~___FILEBASENAME___()
{
    m_instance = NULL;
}

___FILEBASENAME___* ___FILEBASENAME___::getInstance()
{
    if (!m_instance) {
        m_instance = new ___FILEBASENAME___();
    }
    return m_instance;
}

