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
const char floor          = '.';


enum INPUT
  {
   LEFT = 'q',
   RIGHT = 'd',
   TOP = 'z',
   BOTTOM = 's',
   STOP = 'x'
  };




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

void Interface::displayInit()
{
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

void Interface::drawMap(Map* map)
{
    int mapLineSize = map->lineSize;
    int mapColSize  = map->colSize;

    char* mapToDraw = map->mergeLayout();

    for (int i = 0; i < mapColSize; i++)
    {
        for (int j = 0; j < mapLineSize; j++)
        {
            move(i,j);
            addch(mapToDraw[i*mapLineSize+j]);
            //std::cout << mapToDraw[i*mapColSize+j] << std::endl;
        }
    }
    refresh();
}

void Interface::drawStats(Character* player)
{

    move(sizev-1,0);

    std::string health = std::to_string(player->getHealth());
    /* std::string armor = std::to_string(player->getArmorVal());
    std::string atk = std::to_string(player->getWeaponVal()); */

    std::string stats;

    stats = " PV = " + health + "    Armor = 20    ATK = 25";

    addstr(stats.c_str());
}
 

void Interface::refreshInterface(Character* player) {
    // this->drawStats(player);
    this->drawPlayer(player);

    move(sizev, sizeh);
    refresh();
}

void Interface::drawPlayer(Character* player)
{
    std::array<int, 2> coords = player->getCoordinates();

    move(coords[0], coords[1]);
    addch('@');

    refresh();
}