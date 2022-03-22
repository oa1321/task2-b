/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include <iostream>
#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;
#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */

TEST_CASE("shood not raise an error"){
    /*
    check if error is not raised when writing to a notebook in line (legel is when col 0 to 99)
    */
    Notebook notebook;

    for(unsigned int i = 0; i < 100; i++){
        CHECK_NOTHROW(notebook.write(0,0,i,Direction::Horizontal,"a"));
    }
    for(unsigned int i = 0; i < 100; i++){
        CHECK_NOTHROW(notebook.read(0,0,i,Direction::Horizontal, 1));
    }
    for(unsigned int i = 0; i < 100; i++){
        CHECK_NOTHROW(notebook.erase(0,0,i,Direction::Horizontal, 1));
    }
}

TEST_CASE("shood raise an error"){
    /*
    check if error is raised when writing to a notebook in a line (ilegel is when col >= 100)
    */
    Notebook notebook;

    for(unsigned int i = 100; i < 1000; i++){
        CHECK_THROWS(notebook.write(0,0,i,Direction::Horizontal,"a"));
    }
    for(unsigned int i = 100; i < 1000; i++){
        CHECK_THROWS(notebook.read(0,0,i,Direction::Horizontal, 1));
    }
    for(unsigned int i = 100; i < 1000; i++){
        CHECK_THROWS(notebook.erase(0,0,i,Direction::Horizontal, 1));
    }
}

TEST_CASE("shood raise an error"){
    /*
    chekc if error is raisen when writing  on a col when this col were erased before (legel is when col 0 to 99)
    */
    Notebook notebook;

    for(unsigned int i = 0; i < 100; i++){
        CHECK_NOTHROW(notebook.erase(0,0,i,Direction::Horizontal, 1));
        CHECK_THROWS(notebook.write(0,0,i,Direction::Horizontal,"a"));
    }
}

TEST_CASE("shood raise an error"){
    /*
    chekc if error is raisen when writing  on a col when this col were written before (legel is when col 0 to 99)
    */
    Notebook notebook;

    for(unsigned int i = 0; i < 100; i++){
        CHECK_NOTHROW(notebook.write(0,0,i,Direction::Horizontal,"a"));
        CHECK_THROWS(notebook.write(0,0,i,Direction::Horizontal,"a"));
    }
}

TEST_CASE("shood not raise an error"){
    /*
    chekc if erase  on a col when this col were erase before is legel(legel is when col 0 to 99)
    */
    Notebook notebook;

    for(unsigned int i = 0; i < 100; i++){
        CHECK_NOTHROW(notebook.erase(0,0,i,Direction::Horizontal,1));
        CHECK_NOTHROW(notebook.erase(0,0,i,Direction::Horizontal,1));
    }
}

TEST_CASE("shood not raise an error"){
    /*
    chekc if you can read any size of line from 1 to 100 (index 0 to 99)
    check if you can write on any size of line from 1 to 100 (index 0 to 99)
    check if you can't write on any size of line from 100 to 1000+ (index 100 to 1999)
    */
    Notebook notebook;

    for(unsigned int i = 0; i < 100; i++){
        CHECK_NOTHROW(notebook.read(i,0,0,Direction::Horizontal,i));
    }
    for(unsigned int i = 0; i < 100; i++){
        string test_str = "";
        for(unsigned int j = 0; j < i; j++){
            test_str.append("a");
        }
        CHECK_NOTHROW(notebook.write(i,0,0,Direction::Horizontal, test_str));
    }
    for(unsigned int i = 100; i < 1000; i++){
        string test_str = "";
        for(unsigned int j = 0; j < i; j++){
            test_str.append("a");
        }
        CHECK_THROWS(notebook.write(i,1,0,Direction::Horizontal, test_str));
    }
}

TEST_CASE("shood not raise an error"){
    /*
    check if you can erase on any size of line from 1 to 100 (index 0 to 99)
    check if you can't erase on any size of line from 100 to 1000+ (index 100 to 1999)
    */
    Notebook notebook;

    for(unsigned int i = 0; i < 100; i++){
        CHECK_NOTHROW(notebook.erase(i,0,0,Direction::Horizontal, i));
    }
    for(unsigned int i = 100; i < 1000; i++){
        CHECK_THROWS(notebook.erase(i,1,0,Direction::Horizontal, i));
    }
}

TEST_CASE("shood not raise an error"){
    /*
    check if reading and writing are working 
    */
    Notebook notebook;

    for(unsigned int i = 0; i < 100; i++){
        for(unsigned int j = 0; j < 100; j++){
            CHECK_NOTHROW(notebook.write(0,i,j,Direction::Horizontal, "i"));
        }
    }
    for(unsigned int i = 0; i < 100; i++){
        for(unsigned int j = 0; j < 100; j++){
            CHECK(notebook.read(0,i,j,Direction::Horizontal, 1) == "i");
        }
    }

    for(unsigned int i = 0; i < 100; i++){
        for(unsigned int j = 0; j < 100; j++){
            CHECK_NOTHROW(notebook.erase(0,i,j,Direction::Horizontal, 1));
        }
    }
    for(unsigned int i = 0; i < 100; i++){
        for(unsigned int j = 0; j < 100; j++){
            CHECK(notebook.read(0,i,j,Direction::Horizontal, 1) == "~");
        }
    }
    
}

TEST_CASE("shood not raise an error"){
    /*
    check vertical writing and reading and erasing with line size more than 100
    */
    Notebook notebook;
    
    string test_str;
    test_str = string(300, 'a');

    CHECK_NOTHROW(notebook.write(0,0,0,Direction::Vertical,test_str));
    CHECK_NOTHROW(notebook.read(0,0,0,Direction::Vertical,test_str.size()));
    CHECK_NOTHROW(notebook.erase(0,0,0,Direction::Vertical,test_str.size()));
    

}


TEST_CASE("shood raise an error in the first line"){
    /*
    checks spcial cases  (writning _ or ~ is ilegel)
    */
    Notebook notebook;
    
    string test_str;
    test_str = string(50, '~');

    CHECK_THROWS(notebook.write(0,0,0,Direction::Vertical,test_str));
    test_str = string(50, '_');
    CHECK_NOTHROW(notebook.write(0,0,0,Direction::Vertical,test_str));
    test_str = string(50, 'a');
    CHECK_NOTHROW(notebook.write(0,0,0,Direction::Vertical,test_str));
}

// TEST_CASE("shood raise an error "){
//     //negetive number in row col and page will raise an error and show
//     Notebook notebook;
//     CHECK_THROWS(notebook.write(-1,0,0,Direction::Horizontal,"a"));
//     CHECK_THROWS(notebook.write(0,-1,0,Direction::Horizontal,"a"));
//     CHECK_THROWS(notebook.write(0,0,-1,Direction::Horizontal,"a"));
 
//     CHECK_THROWS(notebook.read(-1,0,0,Direction::Horizontal,1));
//     CHECK_THROWS(notebook.read(0,-1,0,Direction::Horizontal,1));
//     CHECK_THROWS(notebook.read(0,0,-1,Direction::Horizontal,1));

//     CHECK_THROWS(notebook.erase(-1,0,0,Direction::Horizontal,1));
//     CHECK_THROWS(notebook.erase(0,-1,0,Direction::Horizontal,1));
//     CHECK_THROWS(notebook.erase(0,0,-1,Direction::Horizontal,1));
    
//     CHECK_THROWS(notebook.show(-1));
// }