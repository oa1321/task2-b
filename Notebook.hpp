#include <iostream>
#include <stdexcept>
using namespace std;
#include <string>
#include <array>
#include <algorithm>
#include "Direction.hpp"
using ariel::Direction;

namespace ariel {
    class Notebook
    {
        public:
            const unsigned int row_length = 100;
            Notebook();
            ~Notebook();
            void write(unsigned int page,unsigned int row,unsigned int column, Direction direction, const string& text) const ;
            string read(unsigned int page,unsigned int row,unsigned int column, Direction direction, unsigned int length) const ;
            void erase(unsigned int page,unsigned int row,unsigned int column, Direction direction, unsigned int length) const ;
            void show(unsigned int page) const ;
    };

    
}
namespace ariel{
    class Page {

        public:
            const unsigned int row_length = 100;
            Page();
            ~Page();
    };
}