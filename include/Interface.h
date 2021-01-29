#include <iostream>
#include <string>
#include <array>
#include <vector>
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
        void drawStats(Character* player);
        void drawPlayer(Character* player);
        void refresh();
};