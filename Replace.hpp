//
//  Replace.hpp
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#ifndef Replace_hpp
#define Replace_hpp

#include "ICommand.h"
#include <string>

using namespace std;

class Replace : public ICommand
{
private:
    const string m_findStr;
    const string m_replaceStr;
public:
    explicit Replace( const string& findStr, const string& replaceStr );
    virtual shared_ptr<ICommand> execute( string& buf );
    ~Replace();
};

#endif /* Replace_hpp */
