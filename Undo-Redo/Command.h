//
//  Command.h
//  undo-redo-four
//
//  Created by Cathy on 2016/12/07.
//  Copyright © 2016年 Cathy. All rights reserved.
//

#ifndef Command_h
#define Command_h

#include <iostream>
#include <stack>
#include <string>

class Command
{
public:
    Command(){}
    virtual ~Command(){}
    
    virtual void Execute() = 0;
};


class InputCommand : public Command
{
public:
    
    InputCommand( const std::string &input )
    {
        mInput = input;
    }
    ~InputCommand()
    {}
    
    void Execute()
    {
        printf( "current string: %s\n", mInput.c_str() );
    }
  
private:
    
    std::string mInput;
};

class Commander
{
public:
    Commander( Command *pCmd )
    {
        //最初的命令数据
        mUndo.push( pCmd );
    }
    ~Commander()
    {
        while( false == mUndo.empty() )
        {
            delete mUndo.top();
            mUndo.pop();
        }
        while( false == mRedo.empty() )
        {
            delete mRedo.top();
            mRedo.pop();
        }
    }
    
    void ExecuteCommand( Command *pCmd )
    {
        pCmd->Execute();
        mUndo.push( pCmd );
    }
    
    void Undo()
    {
        if( mUndo.size() < 2 )
        {
            //无法后退撤销没有数据
            printf( "undo failed.\n" );
            return;
        }
        
        printf( "undo:\n" );
        
        //当前命令
        auto pCmd = mUndo.top();
        
        //保存当前命令
        mRedo.push( pCmd );
        
        //弹出
        mUndo.pop();
        
        //还原到上个命令
        pCmd = mUndo.top();
        
        pCmd->Execute();
    }  
  
    void Redo()
    {
        if( mRedo.empty() )
        {
            //无法前进重做没有数据
            printf( "redo failed.\n" );
            return;
        }
        
        printf( "redo:\n" );
        
        auto pCmd = mRedo.top();
        
        pCmd->Execute();
        
        mRedo.pop();
        
        mUndo.push( pCmd );
    }
    
private:
    std::stack< Command* > mUndo;
    std::stack< Command* > mRedo;
};

#endif /* Command_h */
