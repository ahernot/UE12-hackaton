#include <iostream>
#include <string>
#include <ncurses.h>
#include <iomanip>
#include "Map.h"
#include "character.h"

#pragma once

class Interface {
    protected:
        char* _display;
    public :
        Interface();
        ~Interface();
        void displayInit();
        void drawMap();
        void drawStats();
};