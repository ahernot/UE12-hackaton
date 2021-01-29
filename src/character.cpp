#include <string>
#include "character.h"

Character::Character (const int& type, const int& x, const int& y) _type(type), _xPos(x), _yPos(y) {  
};



std::array<int, 2> Character::getCoordinates () {
    std::array<int, 2> coordinates = {this->_xPos, this->_yPos};
    return coordinates;
};

int Character::getType () {
    return this->_type;
};




// Armor
int Character::getArmorVal () {
    int armorVal = 0;
    for (std::array<ArmorItem*, 4>::iterator armorIterator = this->_armor.begin(); armorIterator < this->_armor.end(); armorIterator ++) {
        armorVal += (*armorIterator)->getDefensePoints();
    };
    return armorVal;
};

/**
 * Replace armor in armor inventory
 * @param newArmor new armor piece to add
 * @return old armor piece
 */
ArmorItem* Character::replaceArmor (ArmorItem* newArmor) {
    int newArmorType = newArmor->getType(); // get new armor type
    ArmorItem* oldArmor = (this->_armor)[newArmorType]; // Get old armor (with matching type) pointer
    (this->_armor)[newArmorType] = newArmor; // Replace old armor with new armor
    return oldArmor; // return old armor pointer
};

/**
 * Get armor item at specific position
 * @param pos position
 * @return pointer to armor item
 */
ArmorItem* Character::getArmorItem (const int& pos) {
    return (this->_armor)[pos];
};






// Weapons
/**
 * Get character attack points.
 * @return Weapon value
 */
int Character::getWeaponVal () {
    return (this->_weapon)->getAttackPoints();
}

/**
 * Replace weapon in weapon slot
 * @param newWeapon new weapon
 * @return old weapon
 */
WeaponItem* Character::replaceWeapon (WeaponItem* newWeapon) {
    WeaponItem* oldWeapon = (this->_weapon);
    this->_weapon = newWeapon;
    return oldWeapon;
};

/**
 * Get weapon item
 * @return pointer to weapon item
 */
WeaponItem* Character::getWeaponItem () {
    return this->_weapon;
};



// Health management
int Character::getHealth () {
    return this->_health;
}; // return character health
int addHealth (const int& healthToAdd);
int removeHealth (const int& healthToRemove);





/*
void Character::move (const int& x, const int& y) {
    this->_xPos += x;
    this->_yPos += y;
}
*/


void Character::updatePosition (const int& x, const int& y) {
    this->_xPos = x;
    this->_yPos = y;
}

// #inventory -> calculate minecraft armor, 1 weapon
// #health


// DESTRUCTOR WHEN DEAD
// SHIELD TO ACTIVATE, IN OFFHAND?