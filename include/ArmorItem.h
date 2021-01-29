#ifndef _ARMOR_ITEM_H_
#define _ARMOR_ITEM_H_

#include "Item.h"

const vector<string> ARMOR_LINKMAP = {"wood_helmet", "wood_chest", "wood_leggings", "wood_boots"};

class ArmorItem : public Item {
    public:
        ArmorItem(int type = 0, int material = 0);
        ~ArmorItem();
        int getDefensePoints();
        bool isBroken();
        void print();
};

#endif