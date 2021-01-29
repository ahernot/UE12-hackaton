#include "Character.h"


// Class constructor
Character::Character (const int& type, const int& x, const int& y, int health, int baseAttackVal, int baseArmorVal): _type(type), _xPos(x), _yPos(y), _health(health), _baseAttackVal(baseAttackVal), _baseArmorVal(baseArmorVal) { 
    this->_alive = true; 
};

// Class destructor
Character::~Character () {
    // destroy
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
    int armorVal = this->_baseArmorVal;
    /* for (std::array<ArmorItem*, 4>::iterator armorIterator = this->_armor.begin(); armorIterator < this->_armor.end(); armorIterator ++) {
        armorVal += (*armorIterator)->getDefensePoints();
    }; */
    for(int i = 0; i<4; i++) {
        armorVal += (this->_armor)[i]->getDefensePoints();
    }
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


void Character::clearArmor () {
    for (int i = 0; i < 4; i ++) {
        (this->_armor)[i] = nullptr;
    };
};


void Character::clearBrokenArmor () {
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

int Character::getWeaponVal () {
    int attackVal = this->_baseAttackVal;
    attackVal += (this->_weapon)->getAttackPoints();
    return attackVal;
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


void Character::clearWeapon () {
    this->_weapon = nullptr;
};


void Character::clearBrokenWeapon () {
    if ((this->_weapon)->getDurability() <= 0) {
        this->_weapon = nullptr; // delete pointer (DELETE OBJECT???)
    };
};






// Health management

int Character::getHealth () {
    return this->_health;
};


int Character::addHealth (const int& healthToAdd) {
    this->_health += healthToAdd;
};


int Character::removeHealth (const int& healthToRemove) {
    this->_health -= healthToRemove;
};


void Character::clearHealth () {
     this->_health = 0;
 };






// Inventory management

std::array<Item*, INVENTORY_SIZE> Character::getInventory () {
    return this->_inventory;
};


Item* Character::getInventory (const int& pos) {
    return (this->_inventory)[pos];
};

/**
 * Add item to inventory in the first vacant slot, or in the last slot (returning the item it replaces).
 */
Item* Character::replaceInventory (Item* newItem) {
    for (int i = 0; i < INVENTORY_SIZE; i ++) {
        Item* inventoryItem = (this->_inventory)[i]; // works?
        if (inventoryItem == nullptr) {
            (this->_inventory)[i] = newItem;
            return nullptr;
        };

        return Character::replaceInventory(newItem, INVENTORY_SIZE - 1);
    };
};



Item* Character::replaceInventory (Item* newItem, const int& pos) {
    Item* oldItem = (this->_inventory)[pos];
    (this->_inventory)[pos] = newItem;
    return oldItem;
};


void Character::removeInInventory (const int& pos) {
    (this->_inventory)[pos] = nullptr;
}; // delete if broken, with isBroken method from Item


/**
 * Clear all player inventory
 */

void Character::clearInventory () {
    for (int i = 0; i < INVENTORY_SIZE; i ++) {
        (this->_inventory)[i] = nullptr;
    };
}


/**
 * Clear all broken in player inventory
 */

void Character::clearBrokenInInventory () {
    for (int i = 0; i < INVENTORY_SIZE; i ++) {
        Item* inventoryItem = (this->_inventory)[i]; // works?
        if (inventoryItem->getDurability() <= 0) {
            (this->_inventory)[i] = nullptr; // delete pointer (DELETE OBJECT???)
        };
    };
};











void Character::clearBroken () {
    this->clearBrokenArmor ();
    this->clearBrokenWeapon ();
    // Clean broken items in inventory // TODO
};



void Character::clearAllInventories () {
        this->clearArmor();
        this->clearWeapon();
        this->clearInventory();
    };



void Character::updatePosition (const int& x, const int& y) {
    this->_xPos = x;
    this->_yPos = y;
}


void Character::updateStatus () {
    if (this->_health <= 0) {
        this->_alive = false;
    };
};

bool Character::isAlive () {
    return this->_alive;
};



// DESTRUCTOR WHEN DEAD
// SHIELD TO ACTIVATE, IN OFFHAND?
// Regeneration?
