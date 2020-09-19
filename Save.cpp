//
//  Save.cpp
//  Buffer
//
//  Created by Sri on 7/20/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#include "Save.hpp"
#include <fstream>
#include <regex>
#include <iostream>

using namespace std;

Save::Save( const string& filePath ) :
    m_filePath( filePath )
{
    
}

shared_ptr<ICommand>Save::execute( string& buf )
{
    cout << "Filepath: " << m_filePath.c_str() << endl;
    if( m_filePath.empty() ) throw ("Empty filepath");
    
    /*
     Save operation is intentionally left out undo/redo operation.
     Rationale: Undo save operation behaviour is ambigious and needs clarity.
                Should undo save operation revert the changes made to the file?
     */
    shared_ptr<ICommand> cmd = nullptr;
    try
    {
        if( regex_match(m_filePath, regex("(.*).txt",std::regex_constants::icase) ) )
        {
            ofstream file (m_filePath);
            if ( file.is_open() )
            {
                file << buf.c_str();
                file.close();
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

Save::~Save()
{
    
}
