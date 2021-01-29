#include "Character.h"
#include "Map.h"
#include "Interface.h"
#include "move.cpp"

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
    int dir = 0;
    // Main loop
    while(player->isAlive()) {
        // Get map
        // char* mapLine = map->mergeLayout();
        c = getch();
        switch(c) {
            case 'z':
                dir = 1;
                break;
            case 'q':
                dir = 2;
                break;
            case 'd':
                dir = 3;
                break;
            case 's':
                dir = 0;
                break;
        }
        move(player, map, dir);

        // Refresh interface
        i.refreshInterface(player);
    }

    return 0;
}