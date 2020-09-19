//
//  Erase.hpp
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#ifndef Erase_hpp
#define Erase_hpp

#include "ICommand.h"
#include <string>

using namespace std;

class Erase : public ICommand
{
private:
    const size_t m_pos;
    const size_t m_numCharsToErase;
public:
    explicit Erase( const size_t pos = 0, const size_t numChars = string::npos );
    virtual shared_ptr<ICommand> execute( string& buf );
    
    ~Erase();
};

#endif /* Erase_hpp */
