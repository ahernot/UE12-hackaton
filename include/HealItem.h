#ifndef _HEAL_ITEM_H_
#define _HEAL_ITEM_H_

#include "Item.h"

const vector<string> HEAL_LINKMAP = {"potion"};

class HealItem : public Item {
    public:
        HealItem(int number = 0);
        ~HealItem();
        int getHealPoints();
        void print();
};

#endif