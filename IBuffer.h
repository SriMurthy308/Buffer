//
//  IBuffer.h
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#ifndef IBuffer_h
#define IBuffer_h

#include <string>
using namespace std;

class IBuffer
{
public:
    virtual const string& insert( const string& subStr, size_t pos ) = 0;
    virtual const string& append( const string& subStr ) = 0;
    virtual const string& erase( size_t pos, size_t numChars ) = 0;
    virtual const string& erase( size_t numChars ) = 0;
    virtual const string& replace( const string& findStr, const string& replaceStr ) = 0;
    virtual const string& undo() = 0;
    virtual const string& redo() = 0;
    virtual void load( const string& filePath ) = 0;
    virtual void save( const string& filePath ) = 0;
};


#endif /* IBuffer_h */
