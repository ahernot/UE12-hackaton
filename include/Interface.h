#include <iostream>
#include <string>
#include <ncurses.h>
#include <iomanip>
#include "Map.h"
#include "character.h"
#include "Item.h"

#pragma once

class Interface {
    protected:
        char* _display;
    public :
        Interface();
        ~Interface();
        void displayInit();
        void drawMap(Map* map);
        void drawStats(Character<DEFAULT_INVENTORY_SIZE>* player);
        void refresh();
};