#include "Character.h"
#include "Map.h"
#include "Interface.h"
#include "move.cpp"
#include "config.h"

int main () {
    // Initial positions
    int xInit = 2;
    int yInit = 2;

    // Initialise player
    Character* player = new Character(0, xInit, yInit, DEFAULT_HEALTH, BASE_ATTACK_VALUE, BASE_ARMOR_VALUE);

    // Initialise map
    Map* map = new Map();

    // Initialise interface
    Interface i;
    i.displayInit();
    i.drawMap(map);

    char c = '\0';
    int dir = -1;
    // Main loop
    while(player->isAlive()) {
        // Get map
        // char* mapLine = map->mergeLayout();
        c = getch();
        switch(c) {
            case TOP:
                dir = 1;
                break;
            case LEFT:
                dir = 2;
                break;
            case RIGHT:
                dir = 3;
                break;
            case BOTTOM:
                dir = 0;
                break;
            case STOP:
                return 0;
                break;
            default:
                dir = -1;
                break;
        }
        if(dir != -1) {
            move(player, map, dir);
        }

        // Refresh interface
        i.refreshInterface(player);
    }

    // Clean objects
    delete player;
    delete map;

    return 0;
}