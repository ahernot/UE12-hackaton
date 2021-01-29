#ifndef _WEAPON_ITEM_H_
#define _WEAPON_ITEM_H_

#include "Item.h"

const vector<string> WEAPON_LINKMAP = {"wood_sword"};

class WeaponItem : public Item {
    public:
        WeaponItem(int type = 0, int material = 0);
        ~WeaponItem();
        int getAttackPoints();
        bool isBroken();
        void print();
};

#endif