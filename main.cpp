#include "Character.h"
#include "Map.h"
#include "Interface.h"

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

    // Main loop
    while(player->isAlive()) {
        // Get map
        // char* mapLine = map->mergeLayout();

        // Refresh interface
        i.refreshInterface(player);
    }

    return 0;
}