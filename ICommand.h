//
//  ICommand.h
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#ifndef ICommand_h
#define ICommand_h

#include <string>
using namespace std;

class ICommand
{
public:
    virtual shared_ptr<ICommand> execute( string& str ) = 0;
};


#endif /* ICommand_h */
