#include <iostream>
#include <stdexcept>
#include "Notebook.hpp"
using namespace std;
#include <string>
#include <array>
#include <algorithm>
#include "Direction.hpp"
using ariel::Direction;

ariel::Notebook::Notebook() {
    cout << "Notebook constructor" << endl;
}

ariel::Notebook::~Notebook() {
    cout << "Notebook destructor" << endl;
}

string ariel::Notebook::read(unsigned int page,unsigned int row,unsigned int column, Direction direction,unsigned int length) const {
    if (column < 0 || column >= row_length ) {
        throw out_of_range("out of range");
    }
    cout << "Notebook read" << ariel::Notebook::row_length << endl;
    return "";
}

void ariel::Notebook::write(unsigned int page,unsigned int row,unsigned int column, Direction direction, const string& text) const {
    if (column < 0 || column >= row_length ) {
        throw out_of_range("out of range");
    }
    cout << "Notebook write" << ariel::Notebook::row_length << endl;
}

void ariel::Notebook::erase(unsigned int page,unsigned int row,unsigned int column, Direction direction,unsigned int length) const {
    if (column < 0 || column >= row_length ) {
        throw out_of_range("out of range");
    }
    cout << "Notebook erase" << ariel::Notebook::row_length << endl;
}
void ariel::Notebook::show(unsigned int page) const {
    cout << "Notebook show" << ariel::Notebook::row_length << endl;
}

ariel::Page::Page() {
    cout << "Page constructor" << endl;
}
ariel::Page::~Page() {
    cout << "Page destructor" << ariel::Page::row_length << endl;
}

