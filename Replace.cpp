//
//  Replace.cpp
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#include "Replace.hpp"
#include <iostream>

Replace::Replace( const string& findStr, const string& replaceStr ) :
    m_findStr(findStr),
    m_replaceStr(replaceStr)
{
    
}

Replace::~Replace()
{
    
}

shared_ptr<ICommand> Replace::execute( string& buf )
{
    shared_ptr<ICommand> cmd = nullptr;
    try
    {
        if( buf.empty() )
        {
            cout << "Buffer is empty. Nothing to replace." << endl;
            return cmd;
        }
        cout << "REPLACE all occurrences of \"" << m_findStr << "\"" << " with \"" << m_replaceStr
             << "\" in \""
             << buf << "\"" << endl;
        size_t index = 0;
        size_t len = m_findStr.length();
        index = buf.find( m_findStr, index);
        
        if( index != std::string::npos )
        {
            cmd = make_shared<Replace>(m_replaceStr, m_findStr );
            while ( index != std::string::npos )
            {
                buf.replace(index, len, m_replaceStr );
                index += len;
                index = buf.find( m_findStr, index);
            }
        }
        cout << "\"" << buf << "\"" << endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Software internal error occurred while finding "
                  << m_findStr.c_str()
                  << " and replacing with "
                  << m_replaceStr.c_str()
                  << ". Reason: " << e.exception::what() << std::endl;
        throw(e);
    }
    catch(...)
    {
        std::cerr << "Unknown exception occurred while finding \'"
                  << m_findStr.c_str()
                  << " and replacing with "
                  << m_replaceStr.c_str();
        throw "Unknown exception occurred";
    }
    
    return cmd;
}

