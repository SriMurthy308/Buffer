//
//  Save.hpp
//  Buffer
//
//  Created by Sri on 7/20/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#ifndef Save_hpp
#define Save_hpp

#include "ICommand.h"

class Save : public ICommand
{
private:
    const string m_filePath;
public:
    explicit Save( const string& filePath );
    virtual shared_ptr<ICommand> execute( string& buf );
    ~Save();
};

#endif /* Save_hpp */
