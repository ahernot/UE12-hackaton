#include "Interface.h"
#include <iostream>


int sizeh = 125;
int sizev = 32;

int window_left   = 1;
int window_top    = 2;
int window_bottom = sizev + window_top;
int window_right  = window_left + sizeh;

const char player         = '@';
const char upperLowerWall = '_';
const char leftRightWall  = '|';
const char ffloor          = '.';

bool is_direction (char c) {
  return ((c == LEFT) or (c == RIGHT)
	  or (c == BOTTOM) or (c == TOP));
}

Interface::Interface()
{
    int size = sizeh*(sizev);
    char* display = new char [size];


    for (int i = 0; i < size; ++i) 
    {
        display[i] = ' ';
    }

    this->_display = display;
}

Interface::~Interface(){}


/**
 * Initialise interface
 */
void Interface::displayInit()
{

    // Initialise canvas
    initscr();
    clear();
    noecho();
    cbreak();
    
    for(int i = 0; i<sizev; i++) {
        for(int j = 0; j<sizeh; j++) {
            move(i,j);
            addch(this->_display[j+i*sizeh]);
        }
    }
    refresh();
    
}


/**
 * Draw map
 * @param map pointer to Map
 */
void Interface::drawMap(Map* map)
{

    // Fetch map dimensions
    int mapLineSize = map->lineSize; // horizontal size
    int mapColSize  = map->colSize; // vertical size

    // Fetch map char array
    char* mapToDraw = map->mergeLayout();

    // Draw map characters
    for (int i = 0; i < mapColSize; i++) // iterate through lines (y-axis)
    {
        for (int j = 0; j < mapLineSize; j++) // iterate through columns (x-axis)
        {
            move(i,j);
            addch(mapToDraw[i*mapLineSize+j]);
        }
    }

    // Refresh canvas
    refresh();
}


/**
 * Draw stats on interface
 * @param player pointer to player Character (needed?)
 */
void Interface::drawStats(Character* player)
{

    // Move to bottom left of window??
    move(0, sizev-1);

    // Fetch player stats
    std::string health = std::to_string(player->getHealth());
    std::string armor = std::to_string(player->getArmorVal());
    std::string atk = std::to_string(player->getWeaponVal());

    // Concatenate stats into string to display
    std::string stats;
    stats = " PV = " + health + "    Armor = " + armor + "   ATK = " + atk;

    // Display stats
    addstr(stats.c_str());
}
 

/**
 * Refresh interface
 * @param player pointer to player Character (needed?)
 */
void Interface::refreshInterface(Character* player) {

    // Draw player stats
    this->drawStats(player);

    // Draw player (MISSING: ERASE LAST PLAYER POSITION)
    this->drawPlayer(player);

    move(sizev, sizeh);

    // Refresh canvas
    refresh();
}


/**
 * Draw player
 * @param player pointer to player Character (needed?)
 */ 
void Interface::drawPlayer(Character* player)
{
    // Fetch player coordinates
    std::array<int, 2> coords = player->getCoordinates();

    // Draw player
    move(coords[0], coords[1]);
    addch('@');
}


/**
 * TODO:
 * erase last player position
 */
