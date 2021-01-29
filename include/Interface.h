#include <iostream>
#include <string>
#include <ncurses.h>
#include <iomanip>

#pragma once

class Interface {
    protected:
        char* _display;
    public :
        Interface();
        ~Interface();
        void displayInit();
};