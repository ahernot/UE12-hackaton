#include "Item.h"

const array<string> WEAPON_LINKMAP = {"wood_sword"};

class WeaponItem : public Item {
    public:
        WeaponItem(int type = 0, int material = 0);
        ~WeaponItem();
        int getArmorPoints();
        bool isBroken();
};