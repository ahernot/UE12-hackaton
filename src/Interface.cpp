#include "Interface.h"


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
   DOWN = 's',
   STOP = 'x'
  };




bool is_direction (char c) {
  return ((c == LEFT) or (c == RIGHT)
	  or (c == DOWN) or (c == TOP));
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

    for (int i = 0; i < mapLineSize; ++i)
    {
        for (int j = 0; j < mapColSize; ++j)
        {
            move(i,j);

            addch(mapToDraw[i*mapLineSize+j]);
        }
    }
}

void Interface::drawStats(Character* player)
{

    move(sizev,0);

    std::string health = std::to_string(player->getHealth());
    std::string armor = std::to_string(player->getArmorVal());
    std::string atk = std::to_string(player->getWeaponVal());

    std::string stats;

    stats = " PV = " + health + "    Armor = " + armor + "    ATK = " + atk;

    addstr(stats.c_str());

}
 

void Interface::clear(Map* map, std::array coords) 
{
    char* fullMap = map->layerMap;
    char cToPlace = fullMap[coords[1] * (map->lineSize) + coords[0]]

    move(x,y);
    addch(cToPlace);
}



void Interface::drawPlayer(Character* player)
{
    std::array<int, 2> coords = player->getCoordinates();

    move(coords[1], coords[0]);
    addch('@');
}



void Interface::refresh(Map* map, Character* player, array<int, 2> newCoords) {

    this->drawStats(player);

    std::array<int, 2> coords = player->getCoorinates();
    this->clear(map, coords);

    player->updatePosition(newCoords[0], newCoords[1]);

    this->drawPlayer(player);

    refresh();

}