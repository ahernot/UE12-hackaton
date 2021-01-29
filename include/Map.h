#ifndef _MAP_H_
#define _MAP_H_

#include <fstream> 
#include <iostream>
#include <vector>

using namespace std;

class Map {
    public:
        Map(string _fileAdress = "assets/lvl1.map");
        void generateItem();
        char* _layerMap;
        char* _layerItem;
    protected:
        string _fileAdress;


};

#endif