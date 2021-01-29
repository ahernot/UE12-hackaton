#include "Item.h"

const array<string> HEAL_LINKMAP = {"potion"};

class HealItem : public Item {
    public:
        HealItem(int number = 0);
        ~HealItem();
        int getHealPoints();
        void print();
};