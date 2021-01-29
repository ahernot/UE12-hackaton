#ifndef _MAP_H_
#define _MAP_H_

#include <fstream>  // for files
#include <iostream> // for files
#include <vector>
#include <stdio.h> // for random
#include <stdlib.h> // for random
#include <time.h> // for a random seed


using namespace std;

class Map {
    public:
        Map(string _fileAdress = "assets/lvl1.map"); // the constructor
        void generateItem(); // generate a random item at a random vacant position
        char* mergeLayout(); // merge layerMap and layerItem for the display
        bool isAccessible(int pos); // return true if the case specified by pos is accessible for the player
        Item* foundSomething(int pos); // return a pointer to the item found on a case and retrieve it from layerItem if there is one, nullptr otherwise
        char* layerMap; // table of the map
        Item* layerItem; // table of the items
        int lineSize; // number of characters per line
        int colSize; // number of characters per collum
    protected:
        string _fileAdress; // adress of the map file, given to the constructor


};

#endif