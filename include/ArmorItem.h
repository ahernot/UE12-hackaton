#include "Item.h"

const array<string> ARMOR_LINKMAP = {"wood_helmet", "wood_chest", "wood_leggings", "wood_boots"};

class ArmorItem : public Item {
    public:
        ArmorItem(int type = 0, int material = 0);
        ~ArmorItem();
        int getArmorPoints();
        bool isBroken();
};