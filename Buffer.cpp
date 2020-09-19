//
//  Buffer.cpp
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#include "Buffer.hpp"
#include "Insert.hpp"
#include "Erase.hpp"
#include "Replace.hpp"
#include "Load.hpp"
#include "Save.hpp"
#include <iostream>

ostream& operator << ( ostream& out, const Buffer& buffer )
{
    out << buffer.m_str.c_str();
    return out;
}

Buffer::Buffer( const string& str ) :
    m_str(str)
{
    shared_ptr<ICommand> undoCmd = make_shared<Erase>(0, m_str.length() );
    cout << "\"" << m_str << "\"" << endl;
    m_undoStack.push(undoCmd);
}

Buffer::~Buffer()
{
    
}

bool Buffer::operator==(const string& otherStr )
{
        if( m_str == otherStr )
            return true;
        else
            return false;
}

const string& Buffer::insert( size_t pos, const string& subStr )
{
    shared_ptr<ICommand> insert = make_shared<Insert>(pos, subStr );
    shared_ptr<ICommand> undoCmd = insert->execute(m_str);
    if( nullptr != undoCmd  )
        m_undoStack.push(undoCmd);
    return m_str;
}

const string& Buffer::append( const string& subStr )
{
    shared_ptr<ICommand> insert = make_shared<Insert>( m_str.length(), subStr );
    shared_ptr<ICommand> undoCmd = insert->execute(m_str);
    if( nullptr != undoCmd  )
        m_undoStack.push(undoCmd);
    return m_str;
}

const string& Buffer::erase( size_t pos, size_t numChars )
{
    shared_ptr<ICommand> erase = make_shared<Erase>( pos, numChars );
    shared_ptr<ICommand> undoCmd = erase->execute(m_str);
    if( nullptr != undoCmd  )
        m_undoStack.push(undoCmd);
    return m_str;
}

const string& Buffer::erase( size_t numChars )
{
    size_t pos = 0;
    if( numChars < m_str.length() )
    {
        pos = m_str.length() - numChars;
    }

    shared_ptr<ICommand> erase = make_shared<Erase>( pos, numChars );
    shared_ptr<ICommand> undoCmd = erase->execute(m_str);
    if( nullptr != undoCmd  )
        m_undoStack.push(undoCmd);
    return m_str;
}

const string& Buffer::replace( const string& findStr, const string& replaceStr )
{
    shared_ptr<ICommand> replace = make_shared<Replace>(findStr, replaceStr );
    shared_ptr<ICommand> undoCmd = replace->execute(m_str);
    if( nullptr != undoCmd  )
        m_undoStack.push(undoCmd);
    return m_str;
}

const string& Buffer::undo()
{
    cout << "Undo: ";
    if( m_undoStack.empty() )
    {
        std::cout << "Nothing to undo" << std::endl;
        return m_str;
    }
    
    shared_ptr<ICommand> undoCmd = m_undoStack.top();
    m_undoStack.pop();
    
    shared_ptr<ICommand> redoCmd = undoCmd->execute(m_str);
    
    if( redoCmd != nullptr )
        m_redoStack.push(redoCmd);
    
    return m_str;
}
const string& Buffer::redo()
{
    cout << "Redo: ";
    if( m_redoStack.empty() )
    {
        cout << "Nothing to redo" << endl;
        return m_str;
        
    }
    shared_ptr<ICommand> redoCmd = m_redoStack.top();
    m_redoStack.pop();
    
    shared_ptr<ICommand> undoCmd = redoCmd->execute(m_str);
    
    if( undoCmd != nullptr )
        m_undoStack.push(undoCmd);
    
    return m_str;
}

void Buffer::load(const string &filePath)
{
    shared_ptr<ICommand> load = make_shared<Load>(filePath);
    load->execute(m_str);
}

void Buffer::save( const string& filePath )
{
    shared_ptr<ICommand> save = make_shared<Save>(filePath);
    save->execute(m_str);
}
