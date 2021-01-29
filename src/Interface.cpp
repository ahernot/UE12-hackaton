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


    // int line = 0;
    // int row = 0;

    // for (int i = 0; i < size - sizeh ; ++i) 
    // {
    //     row++;

    //     if (i % sizeh == 0)
    //     {
    //         line++;
    //         row = 0;
    //     }
    //     if (row < mapSizex)
    //     {
    //         display[i] = '+';

    //     }
    //     else 
    //     {
    //         display[i] = ' ';
    //     }
    // }

    // int k = size-sizeh;
    // display[k] = 'P';
    // display[k+1] = 'V';
    // display[k+2] = ' ';
    // display[k+3] = '=';
    // display[k+4] = ' ';
    // display[k+5] = '1';
    // display[k+6] = '0';
    // display[k+7] = '0';
    // display[k+8] = ' ';
    // display[k+9] = ' ';
    // display[k+10] = ' ';
    // display[k+11] = ' ';
    // display[k+12] = 'A';
    // display[k+13] = 'R';
    // display[k+14] = 'M';
    // display[k+15] = ' ';
    // display[k+16] = '=';
    // display[k+17] = ' ';
    // display[k+18] = '0';
    // display[k+19] = '=';
    // display[k+20] = ' ';
    // display[k+5] = '1';
    // display[k+6] = '0';
    // display[k+7] = '0';
    // display[k+8] = ' ';
    // display[k+9] = ' ';
    // display[k+10] = ' ';
    // display[k+11] = ' ';
    // display[k+12] = 'A';
    // display[k+13] = 'R';
    // display[k+14] = 'M';
    // display[k+15] = ' ';
    // display[k+20] = ' ';
    // display[k+21] = ' ';
    // display[k+22] = 'A';
    // display[k+23] = 'T';
    // display[k+24] = 'K';
    // display[k+25] = ' ';
    // display[k+26] = '=';
    // display[k+27] = ' ';
    // display[k+28] = '1';
    // display[k+29] = '0';
    // display[k+30] = '0';
    
    // for (int i = k+31; i < size; ++i)
    // {
    //     display[i] = ' ';
    // }

  

    
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

void Interface::drawMap(Map map)
{
    int mapLineSize = map.lineSize;
    int mapColSize  = map.colSize;

    char* mapToDraw = map.mergeLayout();

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

    move(32,0);

    int health = std::to_string(player->getHealth()).c_str();
    int armor = player->getArmorVal();
    int atk = player->getWeaponVal();

    


}
