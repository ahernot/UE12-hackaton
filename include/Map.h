#ifndef _MAP_H_
#define _MAP_H_

#include <fstream> 
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

class Map {
    public:
        Map(string _fileAdress = "assets/lvl1.map");
        void generateItem();
        char* mergeLayout();
        bool isAccessible(int pos);
        Item* foundSomething(int pos);
        char* layerMap;
        Item* layerItem;
        int lineSize;
        int colSize;
    protected:
        string _fileAdress;


};

#endif