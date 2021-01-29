#include "Map.h"

Map::Map(string _fileAddress) 
{
    // Read map file
    ifstream fileMap(_fileAddress); // open the map file 
    if(!fileMap) {
        cout << "Echec de l'ouverture du fichier !" << endl;
    }

    vector<char> mapVector;
    char reading;
    string meta;

    // Read the number of characters per line (written on the first line before the core data)
    getline(fileMap, meta);
    this->lineSize = stoi(meta);

    // Read the map, character by character until the end of the file
    while (fileMap.get(reading)) {
        mapVector.push_back(reading);
    }

    // Generate map layer
    int mapSize = mapVector.size();
    char* map = new char[mapSize];

    // Generate item layer
    Item** items = new Item*[mapSize]; 
    for (int i=0; i<mapSize; ++i) {
        map[i] = mapVector[i];
    }

    this->colSize = mapSize/lineSize;
    this->layerMap = map;
    this->layerItem = items;
}

/**
 * Generate an item in the item layer of the map
 */
void Map::generateItem() {
    int mapSize = (this->lineSize)*(this->colSize);
    srand (time(NULL));
    int pos = rand() % mapSize; 
    while(this->layerMap[pos]!='.' && this->layerItem[pos]!=nullptr) {
        pos = rand() % mapSize; 
    }

    int alea  = rand() % 3;
    if(alea==0)
    {
        this->layerItem[pos] = new WeaponItem(0,0);

    }
    if(alea==1)
    {
        int armor = rand() % 4; 
        this->layerItem[pos] = new ArmorItem(armor,0);
    }
    if(alea==2)
    {
        this->layerItem[pos] = new HealItem(0);
    }
}

char* Map::mergeLayout()
{
    int mapSize = (this->lineSize)*(this->colSize);
    char* mergedMap = new char[mapSize];
    for (int i=0; i<mapSize; ++i)
    {
        if(this->layerItem[i] !=nullptr)
        {
            mergedMap[i]=this->layerItem[i]->getIcon();
        }
        else
        {
            mergedMap[i]=this->layerMap[i];
        }
    }
    return mergedMap;
}

bool Map::isAccessible(int pos)
{
    if(this->layerMap[pos]=='.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

Item* Map::foundSomething(int pos)
{
    if(this->layerItem[pos] != nullptr)
    {
        Item* foundItem = this->layerItem[pos];
        this->layerItem[pos]=nullptr;
        return foundItem;
    }
    else
    {
        return nullptr;
    }
}