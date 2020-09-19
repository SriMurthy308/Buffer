//
//  Load.cpp
//  Buffer
//
//  Created by Sri on 7/20/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#include "Load.hpp"
#include <fstream>
#include <regex>
#include <iostream>
#include "Erase.hpp"

using namespace std;

Load::Load( const string& filePath ) :
    m_filePath( filePath )
{
    
}

shared_ptr<ICommand>Load::execute( string& buf )
{
    cout << "Filepath: " << m_filePath.c_str() << endl;
    
    if( m_filePath.empty() ) throw ("Empty filepath");
    
    /*
     Load operation is intentionally left out undo/redo operation.
     Rationale: Undo load operation behaviour is ambigious and needs clarity.
                Should undo load operation clear the contents of the buffer?
                Or should the buffer go back to last state before load?
     */
    shared_ptr<ICommand> cmd = nullptr;
    try
    {
        if( regex_match(m_filePath, regex("(.*).txt",std::regex_constants::icase) ) )
        {
            ifstream file (m_filePath);
            if ( file.is_open() )
            {
                std::string content( (std::istreambuf_iterator<char>(file) ),
                                     (std::istreambuf_iterator<char>()) );
                file.close();
                buf = content;
            }
            else
            {
                throw ("Unable to open file");
            }
        }
        else
        {
            throw ("Invalid file extension");
        }
    }
    catch( const char* errMsg )
    {
        throw errMsg;
    }
    catch ( ... )
    {
        throw ("Unknown exception caught while loading file" );
    }
    
    return nullptr;
}

Load::~Load()
{
    
}
