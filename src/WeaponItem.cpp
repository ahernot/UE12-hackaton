#include "WeaponItem.h"

WeaponItem::WeaponItem(int type, int material) : Item(WEAPON_LINKMAP[type + 1*material]) {}

int WeaponItem::getAttackPoints() {
    return this->_value;
}

bool WeaponItem::isBroken() {
    return (this->_durability == 0);
}

void WeaponItem::print() {
    Item::print();
    cout << "ATK: " << this->_value << endl;
    cout << "Durability: " << this->_durability << endl;
}