//
//  main.cpp
//  undo-redo-four
//
//  Created by Cathy on 2016/12/09.
//  Copyright © 2016年 Cathy. All rights reserved.
//

#include <iostream>
#include "Command.h"


int main()
{
    //赋值一个特殊的字符串
    Commander *p = new Commander( new InputCommand( "[empty]" ) );
    
    //输入1234
    p->ExecuteCommand( new InputCommand( "1234" ) );
    //输入567
    p->ExecuteCommand( new InputCommand( "567" ) );
    //输入xxx
    p->ExecuteCommand( new InputCommand( "xxx" ) );
    
    //执行一次undo 撤销到 567
    p->Undo();
    //撤销到 1234
    p->Undo();
    
    //undo后中间输入新字符串 insert 覆盖 1234
    p->ExecuteCommand( new InputCommand( "insert" ) );
    
    //执行一次undo 撤销到 1234
    p->Undo();
    
    //撤销到最初情况 [empty]
    p->Undo();

    //执行失败 已经undo到最原始情况
    p->Undo();
    
    //执行一次redo 重做到 1234
    p->Redo();
    //重做到 insert
    p->Redo();
    //重做到 567
    p->Redo();
    
    //redo后中间输入新字符串 insert again 覆盖 567
    p->ExecuteCommand( new InputCommand( "insert again" ) );
    
    //执行一次undo 撤销到567
    p->Undo();
    
    //执行一次redo 重做到 insert again
    p->Redo();
    
    //重做到 xxx
    p->Redo();
    
    //执行失败 已经redo到最新情况
    p->Redo();
    delete p;
    return 0;
}  
