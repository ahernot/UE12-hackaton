#include "Character.h"


// Class constructor
template<int inventorySlots>
Character<inventorySlots>::Character (const int& type, const int& x, const int& y, const int& health=10): _type(type), _xPos(x), _yPos(y), _health(health) {  
};

// Class destructor
Character<inventorySlots>::~Character () {
    // destroy
};



template<int inventorySlots>
std::array<int, 2> Character<inventorySlots>::getCoordinates () {
    std::array<int, 2> coordinates = {this->_xPos, this->_yPos};
    return coordinates;
};

template<int inventorySlots>
int Character<inventorySlots>::getType () {
    return this->_type;
};




// Armor
template<int inventorySlots>
int Character<inventorySlots>::getArmorVal () {
    int armorVal = this->baseArmorVal;
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
template<int inventorySlots>
ArmorItem* Character<inventorySlots>::replaceArmor (ArmorItem* newArmor) {
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
template<int inventorySlots>
ArmorItem* Character<inventorySlots>::getArmorItem (const int& pos) {
    return (this->_armor)[pos];
};

template<int inventorySlots>
void Character<inventorySlots>::clearArmor () {
    for (int i = 0; i < 4; i ++) {
        (this->_armor)[i] = nullptr;
    };
};

template<int inventorySlots>
void Character<inventorySlots>::clearBrokenArmor () {
    for (int i = 0; i < 4; i ++) {
        ArmorItem* armorItem = (this->_armor)[i];
        if (armorItem->getDurability() <= 0) {
            (this->_armor)[i] = nullptr; // delete pointer (DELETE OBJECT???)
        };
    };
};




// Weapons
/**
 * Get character attack points.
 * @return Weapon value
 */
template<int inventorySlots>
int Character<inventorySlots>::getWeaponVal () {
    int attackVal = this->_baseAttackVal;
    attackVal += (this->_weapon)->getAttackPoints();
    return attackVal;
}

/**
 * Replace weapon in weapon slot
 * @param newWeapon new weapon
 * @return old weapon
 */
template<int inventorySlots>
WeaponItem* Character<inventorySlots>::replaceWeapon (WeaponItem* newWeapon) {
    WeaponItem* oldWeapon = (this->_weapon);
    this->_weapon = newWeapon;
    return oldWeapon;
};

/**
 * Get weapon item
 * @return pointer to weapon item
 */
template<int inventorySlots>
WeaponItem* Character<inventorySlots>::getWeaponItem () {
    return this->_weapon;
};

template<int inventorySlots>
void Character<inventorySlots>::clearWeapon () {
    this->_weapon = nullptr;
};

template<int inventorySlots>
void Character<inventorySlots>::clearBrokenWeapon () {
    if ((this->_weapon)->getDurability() <= 0) {
        this->_weapon = nullptr; // delete pointer (DELETE OBJECT???)
    };
};






// Health management
template<int inventorySlots>
int Character<inventorySlots>::getHealth () {
    return this->_health;
};

template<int inventorySlots>
int Character<inventorySlots>::addHealth (const int& healthToAdd) {
    this->_health += healthToAdd;
};

template<int inventorySlots>
int Character<inventorySlots>::removeHealth (const int& healthToRemove) {
    this->_health -= healthToRemove;
};

template<int inventorySlots>
void Character<inventorySlots>::clearHealth () {
     this->_health = 0;
 };






// Inventory management
template<int inventorySlots>
std::array<Item*, inventorySlots> Character<inventorySlots>::getInventory () {
    return this->_inventory;
};

template<int inventorySlots>
Item* Character<inventorySlots>::getInventory (const int& pos) {
    return (this->_inventory)[pos];
};

/**
 * Default method to add to end of inventory (englobe tous les types d'Item ?)
 */
template<int inventorySlots>
Item* Character<inventorySlots>::replaceInventory (Item* newItem) {
    return Character::replaceInventory(newItem, 8); // Replace last item of inventory
};

template<int inventorySlots>
Item* Character<inventorySlots>::replaceInventory (Item* newItem, const int& pos) {
    Item* oldItem = (this->_inventory)[pos];
    (this->_inventory)[pos] = newItem;
    return oldItem;
};

template<int inventorySlots>
void Character<inventorySlots>::removeInInventory (const int& pos) {
    (this->_inventory)[pos] = nullptr;
}; // delete if broken, with isBroken method from Item


template<int inventorySlots>
void Character<inventorySlots>::cleanBroken () {
    this->clearBrokenArmor ();
    this->clearBrokenWeapon ();
    // Clean broken items in inventory // TODO
};


template<int inventorySlots>
void Character<inventorySlots>::clearAllInventories () {
        this->clearArmor();
        this->clearWeapon();
        this->clearInventory();
    };


template<int inventorySlots>
void Character<inventorySlots>::updatePosition (const int& x, const int& y) {
    this->_xPos = x;
    this->_yPos = y;
}

template<int inventorySlots>
void Character<inventorySlots>::updateStatus () {
    if (this->_health <= 0) {
        this->_isAlive = false;
    };
};








// #inventory -> calculate minecraft armor, 1 weapon
// #health


// DESTRUCTOR WHEN DEAD
// SHIELD TO ACTIVATE, IN OFFHAND?