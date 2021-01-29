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
    getline(fileMap, this->lineSize);
    while(fileMap.get(reading))
    {
        mapVector.push_back(reading);
    }
    int mapSize = mapVector.size();
    char* map = new char[mapSize];
    Item* items = new Item*[mapSize]; 
    for (int i=0; i<mapSize; ++i)
    {
        map[i]=mapVector[i];
    }
    this->colSize = mapSize/lineSize;
    this->layerMap = map;
    this->layerItem = items;
}

Map::generateItem()
{
    srand (time(NULL));

    int i = rand() % mapSize; 
    while(map[i]!='.' && items[i]!=nullptr)
    {
        i = rand() % mapSize; 
    }
    this->layerItem[i] = new Item();
}