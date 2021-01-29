#include <iostream>
#include <string>
#include <ncurses.h>
#include <iomanip>
#include "Move.cpp"

#pragma once

class Interface {
    protected:
        char* _display;
    public :
        Interface();
        ~Interface();
        void displayInit();
};