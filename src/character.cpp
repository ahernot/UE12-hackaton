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
WeaponItem* Character::replaceWeapon (const WeaponItem* newWeapon) {

};

/**
 * Replace weapon in weapon slot
 * @param newWeapon new weapon
 * @return old weapon
 */
WeaponItem* Character::getWeaponItem () {
    
};






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