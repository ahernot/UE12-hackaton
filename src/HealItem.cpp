#include "HealItem.h"

HealItem::HealItem(int number) : Item(HEAL_LINKMAP[number]) {}

int HealItem::getHealPoints() {
    return this->_value;
}

void HealItem::print() {
    Item::print();
    cout << "Heal: " << this->_value << " PV" << endl;
    cout << "! Only for one utilisation" << endl;
}