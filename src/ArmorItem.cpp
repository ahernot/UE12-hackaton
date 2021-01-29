#include "ArmorItem.h"

ArmorItem::ArmorItem() : Item("empty") {}

ArmorItem::ArmorItem(int type, int material) : Item(ARMOR_LINKMAP[type + material*4]) {}

int ArmorItem::getDefensePoints() {
    return this->_value;
}

bool ArmorItem::isBroken() {
    return (this->_durability == 0);
}

void ArmorItem::print() {
    Item::print();
    cout << "DEF: " << this->_value << endl;
    cout << "Durability: " << this->_durability << endl;
}