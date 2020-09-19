//
//  Insert.cpp
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#include "Insert.hpp"
#include "Erase.hpp"
#include <iostream>

Insert::Insert( size_t pos, const string& str ) :
    m_subStr(str),
    m_pos( pos )
{
    
}

Insert::~Insert()
{
    
}

shared_ptr<ICommand> Insert::execute( string& buf )
{
    shared_ptr<ICommand> cmd = nullptr;
    try
    {
        cout << "INSERT substring \"" << m_subStr << "\" at " << m_pos << " index to \""
             << buf << "\"" << endl;
        
        cout << "\"" << buf.insert(m_pos, m_subStr) << "\"" << endl;
        cmd = make_shared<Erase>(m_pos, m_subStr.length() );
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Out of range exception occurred while inserting "
                  << m_subStr
                  << " at position "
                  << m_pos
                  << std::endl;
        throw(e);
    }
    catch (std::exception& e)
    {
        std::cerr << "Software internal error occurred while inserting "
                  << m_subStr
                  << " at position "
                  << m_pos
                  << std::endl;
        throw(e);
    }
    catch(...)
    {
        std::cerr << "Unknown exception occurred while inserting \'"
                  << m_subStr
                  << "\' at position "
                  << m_pos
                  << std::endl;
        throw "Unknown exception occurred";
    }
    
    return cmd;
}
