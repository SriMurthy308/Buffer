//
//  Erase.cpp
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#include "Erase.hpp"
#include "Insert.hpp"
#include <iostream>

Erase::Erase( const size_t pos, const size_t numOfChars ) :
    m_numCharsToErase(numOfChars),
    m_pos(pos)
{
    
}

Erase::~Erase()
{
    
}

shared_ptr<ICommand> Erase::execute( string& buf )
{
    shared_ptr<ICommand> cmd = nullptr;
    try
    {        
        if( buf.empty() )
        {
            cout << "Buffer is empty. Nothing to erase." << endl;
            return cmd;
        }
        
        cout << "ERASE " << m_numCharsToErase << " characters from \"" << buf << "\""
             << " at " << m_pos << " index." << endl;
        
        string subStr = buf.substr( m_pos, m_numCharsToErase );
        cout << "\"" << buf.erase(m_pos, m_numCharsToErase) << "\"" << endl;
        cmd = make_shared<Insert>(m_pos, subStr);
    }
    catch( std::out_of_range& e )
    {
        std::cerr << "Out of range exception occurred while erasing characters at position: "
                  << m_pos
                  << " from buffer whose length is "
                  << buf.length()
                  << std::endl;
        throw(e);
    }
    catch( std::exception& e )
    {
        std::cerr << "Software internal error occurred while erasing "
                  << m_numCharsToErase
                  << " characters at position "
                  << m_pos
                  << std::endl;
        throw(e);
    }
    catch(...)
    {
        std::cerr << "Unknown exception occurred while erasing "
                  << m_numCharsToErase
                  << " characters at position "
                  << m_pos
                  << std::endl;
        throw "Unknown exception caught while erasing characters from buffer";
    }
    
    return cmd;
}

