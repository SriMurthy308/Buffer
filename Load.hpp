//
//  Load.hpp
//  Buffer
//
//  Created by Sri on 7/20/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#ifndef Load_hpp
#define Load_hpp

#include "ICommand.h"

class Load : public ICommand
{
private:
    const string m_filePath;
public:
    explicit Load( const string& filePath );
    virtual shared_ptr<ICommand> execute( string& buf );
    ~Load();
};

#endif /* Load_hpp */
