#include "Map.h"

Map::Map(string _fileAdress) 
{
    ifstream fileMap(_fileAdress); 

    if(!fileMap)
    {
        cout << "Echec de l'ouverture du fichier !" << endl;
    }

    vector<char> mapVector;
    char reading;
    while(fileMap.get(reading))
    {
        mapVector.push_back(reading);
    }

    char* map = new char[mapVector.size()];
    char* items = new char[mapVector.size()];
    for (int i=0; i<mapVector.size(); ++i)
    {
        map[i]=mapVector[i];
    }

    this->_layerMap = map;
    this->_layerItem = items;
}