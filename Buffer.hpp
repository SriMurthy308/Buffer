//
//  Buffer.hpp
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#ifndef Buffer_hpp
#define Buffer_hpp

#include "IBuffer.h"
#include <stack>
#include "ICommand.h"
#include <ostream>


class Buffer
{
private:
    string m_str;
    stack< shared_ptr<ICommand> > m_undoStack;
    stack< shared_ptr<ICommand> > m_redoStack;
    
    Buffer( const Buffer& buf );
    const Buffer& operator = ( const Buffer& buf );
    
public:
    explicit Buffer( const string& str = "" );
    ~Buffer();

    friend ostream& operator << ( ostream& out, const Buffer& buffer );
    bool operator==( const string& otherStr );
    
    virtual const string& insert( size_t pos, const string& subStr );
    virtual const string& append( const string& subStr );
    virtual const string& erase( size_t pos, size_t numChars );
    virtual const string& erase( size_t numChars );
    virtual const string& replace( const string& findStr, const string& replaceStr );
    virtual const string& undo();
    virtual const string& redo();
    virtual void load( const string& filePath );
    virtual void save( const string& filePath );
};
#endif /* Buffer_hpp */
