#include "character.h"
#include "config.h"


// Initial positions
int xInit = 0;
int yInit = 0;



// Initialise player
Character<DEFAULT_INVENTORY_SIZE>* player = new Character<DEFAULT_INVENTORY_SIZE> (0, xInit, yInit, DEFAULT_HEALTH, BASE_ATTACK_VALUE, BASE_ARMOR_VALUE)

// Initialise map
Map* map = new Map ();

// Initialise interface
Interface interface;
interface.displayInit();
interface.drawMap();


// Main loop
while !(player->isAlive()) {

    // Get map
    // char* mapLine = map->mergeLayout();

    // Refresh interface
    interface.refresh();


}