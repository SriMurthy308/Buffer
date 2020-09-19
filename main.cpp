//
//  main.cpp
//  Buffer
//
//  Created by Sri on 7/19/20.
//  Copyright © 2020 Sri. All rights reserved.
//

#include <iostream>
#include "Buffer.hpp"
#include <string>



void verify_insert()
{
    Buffer buffer( "def" );
    string expected_str ("def");
    cout << "INSERT TEST 1: Create a buffer" << endl;
    ( buffer == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
        
    cout << "INSERT TEST 2: Insert at the beginning of the buffer" << endl;
    expected_str = "abcdef";
    ( buffer.insert(0, "abc" ) == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    cout << "INSERT TEST 3: Insert at the middle of the buffer" << endl;
    expected_str = "abc def";
    ( buffer.insert(3, " " ) == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    cout << "INSERT TEST 4: Insert at the end of the buffer" << endl;
    expected_str = "abc defghi";
    ( buffer.insert(7, "ghi" ) == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    cout << "INSERT TEST 5: Insert outside the range of the buffer" << endl;
    expected_str = "abc defghi";
    
    try
    {
        buffer.insert(15, "insert_out_of_range" );
    } catch ( ... )
    {
        ( buffer == expected_str ) ?
        ( cout << "PASS: Exception caught." << endl) : ( cout << "FAIL: Expected to throw an exception." << buffer << " != " << expected_str << endl);
    }
}

void verify_append()
{
    Buffer buffer( "abc" );
    string expected_str ("abc");
    cout << "APPEND TEST 1: Create a buffer" << endl;
    ( buffer == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
        
    cout << "APPEND TEST 2: Append a substring." << endl;
    expected_str = "abcdef";
    ( buffer.append( "def" ) == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    cout << "APPEND TEST 3: Append to a empty buffer." << endl;
    Buffer buffer2("");
    expected_str = "xyz";
    ( buffer2.append( "xyz" ) == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer2 << " != " << expected_str << endl);
}

void verify_erase()
{
    Buffer buffer( "abcdefg" );
    string expected_str ("abcdefg");
    cout << "ERASE TEST 1: Create a buffer" << endl;
    ( buffer == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );

    expected_str = "abfg";
    cout << "ERASE TEST 2: Erase 3 characters from the middle of the buffer" << endl;
    ( buffer.erase(2,3) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "bfg";
    cout << "ERASE TEST 3: Erase one character from the beginning of the buffer" << endl;
    ( buffer.erase(0,1) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "bf";
    cout << "ERASE TEST 4: Erase one character from the end of the buffer" << endl;
    ( buffer.erase(1) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "b";
    cout << "ERASE TEST 5: Erase one character from the end of the buffer" << endl;
    ( buffer.erase(1) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "";
    cout << "ERASE TEST 6: Erase one character from the end of the buffer" << endl;
    ( buffer.erase(1) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "";
    cout << "ERASE TEST 6: Erase one character from an empty buffer" << endl;
    ( buffer.erase(1) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );

    buffer.append("abcd");
    cout << "ERASE TEST 7: Erase a character from end of the buffer" << endl;
    expected_str = "abcd";
    ( buffer.erase(4,1) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    cout << "ERASE TEST 8: Erase a character from an index outside the buffer" << endl;
    expected_str = "abcd";
    try
    {
        buffer.erase(5,1);
        cout << "FAIL: Expected exception to be thrown" << endl;
    }
    catch ( ... )
    {
        cout << "PASS: Exception caught." << endl;
    }
    
    cout << "ERASE TEST 9: Erase 10 characters from beginning of the buffer whose length is 4" << endl;
    expected_str = "";
    ( buffer.erase(0,10) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    buffer.append("abcd");
    cout << "ERASE TEST 10: Erase 10 characters from second index of the buffer whose length is 4" << endl;
    expected_str = "ab";
    ( buffer.erase(2,10) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );

    buffer.append( "cd" );
    expected_str = "a";
    cout << "ERASE TEST 11: Erase trailing 3 characters" << endl;
    ( buffer.erase(3) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );

    cout << "ERASE TEST 12: Erase trailing 3 characters from buf whose length is 1" << endl;
    expected_str = "";
    ( buffer.erase(3) == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
}

void verify_replace()
{
    Buffer buffer;
    string expected_str("");
    cout << "REPLACE TEST 1: Create a empty buffer and replace a substring from an empty buffer." << endl;
    ( buffer == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    ( buffer.replace("abc", "xyz") == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    buffer.append( "abc abc abc" );
    expected_str = "abc abc abc";
    ( buffer == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );

    expected_str = "xyz xyz xyz";
    cout << "REPLACE TEST 2: Replace all occurrences of a substring by another." << endl;
    ( buffer.replace("abc", "xyz") == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "xyaxyaxyz";
    cout << "REPLACE TEST 2: Replace all occurrences of a substring by another." << endl;
    ( buffer.replace("z ", "a") == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << "\"" << buffer << "\""<< " != " << expected_str << endl );
    
    expected_str = "xyaxyaxyz";
    cout << "REPLACE TEST 3: No occurrences found." << endl;
    ( buffer.replace("p", "q") == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << "\"" << buffer << "\""<< " != " << expected_str << endl );
}

void verify_load_save()
{
    Buffer buffer;
    cout << "LOAD TEST 1: Load a file whose name is empty" << endl;
    try
    {
        buffer.load("");
        cout << "FAIL: Exception expected." << endl;
    }
    catch ( ... )
    {
        cout << "PASS: Exception caught." << endl;
    }
    
    cout << "LOAD TEST 2: Load a file which is not a TXT file" << endl;
    try
    {
        buffer.load("a.a");
        cout << "FAIL: Exception expected." << endl;
    }
    catch ( ... )
    {
        cout << "PASS: Exception caught." << endl;
    }
    
    cout << "LOAD TEST 3: Load a TXT file that doesnot exist." << endl;
    try
    {
        buffer.load("a.txt");
        cout << "FAIL: Exception expected." << endl;
    }
    catch ( ... )
    {
        cout << "PASS: Exception caught." << endl;
    }
    
    cout << "LOAD TEST 4: Load a TXT file that exists." << endl;
    
    string loadfilePath ("LoadTest.txt");
    
    buffer.load(loadfilePath);
    string expected_str ("abc def hij abc def hij");
    ( buffer == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    cout << "LOAD TEST 5: Load the same TXT file again." << endl;
    
    buffer.load(loadfilePath);
    expected_str = "abc def hij abc def hij";
    ( buffer == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    cout << "SAVE TEST 1: Save to a file whose name is empty" << endl;
    try
    {
        buffer.save("");
        cout << "FAIL: Exception expected." << endl;
    }
    catch ( ... )
    {
        cout << "PASS: Exception caught." << endl;
    }
    
    cout << "SAVE TEST 2: Save to a file which is not a TXT file" << endl;
    try
    {
        buffer.save("a.a");
        cout << "FAIL: Exception expected." << endl;
    }
    catch ( ... )
    {
        cout << "PASS: Exception caught." << endl;
    }
    
    cout << "SAVE TEST 3: Save to a TXT file" << endl;
    buffer.replace( "abc", "xyz" );
    
    string saveFilePath("SaveTest.txt");
    buffer.save(saveFilePath);
    
    cout << "SAVE TEST 4: Save again" << endl;

    buffer.save(saveFilePath);
    
    cout << "Load SaveTest.ext and verify" << endl;
    buffer.load(saveFilePath);
    expected_str = "xyz def hij xyz def hij";
    ( buffer == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
}

void verify_undo_redo()
{
    Buffer buffer( "def" );
    string expected_str ("def");
    cout << "UNDO_REDO TEST 1: Create a buffer. " << endl;
    ( buffer == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "";
    ( buffer.undo() == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "";
    ( buffer.undo() == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "def";
    ( buffer.redo() == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "def";
    ( buffer.redo() == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    expected_str = "";
    ( buffer.undo() == expected_str ) ? ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl );
    
    cout << "UNDO_REDO TEST 2: Insert at the beginning of the buffer." << endl;
    expected_str = "abcdef";
    ( buffer.insert(0, "abcdef" ) == expected_str ) ?
    ( cout << "Insert successful" << endl) : ( cout << "Insert failed: " << buffer << " != " << expected_str << endl);

    expected_str = "";
    ( buffer.undo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);

    expected_str = "abcdef";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);

    expected_str = "defabcdef";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    expected_str = "defabcdef";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);

    expected_str = "abcdef";
    ( buffer.undo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);

    expected_str = "";
    ( buffer.undo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    expected_str = "";
    ( buffer.undo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    cout << "UNDO_REDO TEST 3: Append at the end of the buffer." << endl;
    expected_str = "abcdefabc";
    ( buffer.append("abcdefabc") == expected_str ) ?
    ( cout << "Append successful" << endl) : ( cout << "Append failed: " << buffer << " != " << expected_str << endl);

    expected_str = "";
    ( buffer.undo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);

    expected_str = "abcdefabc";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);

    expected_str = "abcdefabcdefabc";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    expected_str = "defabcdefabcdefabc";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    expected_str = "defabcdefabcdefabc";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    cout << "UNDO_REDO TEST 3: Replace at the end of the buffer." << endl;
    expected_str = "defxyzdefxyzdefxyz";
    ( buffer.replace("abc", "xyz") == expected_str ) ?
    ( cout << "Replace successful" << endl) : ( cout << "Repace failed: " << buffer << " != " << expected_str << endl);

    expected_str = "defabcdefabcdefabc";
    ( buffer.undo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    expected_str = "abcdefabcdefabc";
    ( buffer.undo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    expected_str = "defabcdefabcdefabc";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    expected_str = "defxyzdefxyzdefxyz";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);

    cout << "UNDO_REDO TEST 4: Erase from the beginning of the buffer." << endl;
    expected_str = "defxyzdefxyzdef";
    ( buffer.erase(3) == expected_str ) ?
    ( cout << "Erase successful" << endl) : ( cout << "Erase failed: " << buffer << " != " << expected_str << endl);
    
    expected_str = "defdefxyzdef";
    ( buffer.erase(3,3) == expected_str ) ?
    ( cout << "Erase successful" << endl) : ( cout << "Erase failed: " << buffer << " != " << expected_str << endl);

    expected_str = "defxyzdefxyzdef";
    ( buffer.undo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);

    expected_str = "defxyzdefxyzdefxyz";
    ( buffer.undo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);

    expected_str = "defabcdefabcdefabc";
    ( buffer.undo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    expected_str = "defxyzdefxyzdefxyz";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
    
    expected_str = "defxyzdefxyzdef";
    ( buffer.redo() == expected_str ) ?
    ( cout << "PASS" << endl) : ( cout << "FAIL: " << buffer << " != " << expected_str << endl);
}

int main(int argc, const char * argv[])
{
    try
    {
        cout << "\n\n############ VERIFY INSERT OPERATIONS #################\n\n";
        verify_insert();
        cout << "\n\n############ VERIFY APPEND OPERATIONS #################\n\n";
        verify_append();
        cout << "\n\n############ VERIFY ERASE OPERATIONS #################\n\n";
        verify_erase();
        cout << "\n\n############ VERIFY REPLACE OPERATIONS #################\n\n";
        verify_replace();
        cout << "\n\n############ VERIFY REDO-UNDO OPERATIONS #################\n\n";
        verify_undo_redo();
        cout << "\n\n############ VERIFY LOAD-SAVE OPERATIONS #################\n\n";
        verify_load_save();
        cout << "\n\n########################## END #################\n\n";
    }
    catch( const char* msg )
    {
        cerr << "Exception caught. Error: " << msg << endl;
    }
    catch ( std::out_of_range& e )
    {
        cerr << "Out of range exception caught." << std::endl;
    }
    catch( std::exception& e )
    {
        cerr << "Standard exception caight." << std::endl;
    }
    catch(...)
    {
        cerr << "Unknown exception caught" << endl;
    }
    return 0;
}
