//
//  Insert.hpp
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#ifndef Insert_hpp
#define Insert_hpp

#include "ICommand.h"
#include <string>

using namespace std;

class Insert : public ICommand
{
private:
    const string m_subStr;
    size_t m_pos;
public:
    explicit Insert( size_t pos, const string& str );
    virtual shared_ptr<ICommand> execute( string& buf );
    
    ~Insert();
};

#endif /* Insert_hpp */
