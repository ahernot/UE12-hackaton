#include "character.h"


//------Class constructor and destructor------//

// Class constructor
Character::Character (const int& type, const int& x, const int& y, int health, int baseAttackVal, int baseArmorVal): _type(type), _xPos(x), _yPos(y), _health(health), _baseAttackVal(baseAttackVal), _baseArmorVal(baseArmorVal) { 
    this->_alive = true; 
};

// Class destructor
Character::~Character () {};






//------Character attributes------//

/**
 * Get coordinates of character
 * @return (X, Y) coordinates of the character on the grid
 */
std::array<int, 2> Character::getCoordinates () {
    std::array<int, 2> coordinates = {this->_xPos, this->_yPos};
    return coordinates;
};


/**
 * Get character type
 * @return type of character
 */
int Character::getType () {
    return this->_type;
};





//------Armor------//

/**
 * Get armor protection value
 * @return total armor protection value
 */
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

/**
 * Destroy all armor on character
 */
void Character::clearArmor () {
    for (int i = 0; i < 4; i ++) {
        (this->_armor)[i] = nullptr;
    };
};

/**
 * Remove broken armor (durability = 0) on character
 */
void Character::_clearBrokenArmor () {
    for (int i = 0; i < 4; i ++) {
        ArmorItem* armorItem = (this->_armor)[i];
        if (armorItem->getDurability() <= 0) {
            (this->_armor)[i] = nullptr; // delete pointer (DELETE OBJECT???)
        };
    };
};





//------Weapons------//

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

/**
 * Clear weapon on character
 */
void Character::clearWeapon () {
    this->_weapon = nullptr;
};

/**
 * Remove broken weapon (durability = 0) on character
 */
void Character::_clearBrokenWeapon () {
    if ((this->_weapon)->getDurability() <= 0) {
        this->_weapon = nullptr; // delete pointer (DELETE OBJECT???)
    };
};






//------Health------//

/**
 * Get character's health
 * @return character's health
 */
int Character::getHealth () {
    return this->_health;
};

/**
 * Add health to character
 * @param healthToAdd health to add
 */
void Character::addHealth (const int& healthToAdd) {
    this->_health += healthToAdd;
};

/**
 * Remove health from character
 * @param healthToRemove health to remove
 */
void Character::removeHealth (const int& healthToRemove) {
    this->_health -= healthToRemove;
};

/**
 * Clear character's health (set to 0)
 */
void Character::clearHealth () {
     this->_health = 0;
};






//------Inventory------//

/**
 * Get character's inventory
 * @return character's full inventory
 */
std::array<Item*, INVENTORY_SIZE> Character::getInventory () {
    return this->_inventory;
};

/**
 * Get item from character's inventory
 * @param pos position of item
 * @return item from inventory
 */
Item* Character::getInventory (const int& pos) {
    return (this->_inventory)[pos];
};

/**
 * Add item to inventory in the first vacant slot, or in the last slot (returning the item it replaces).
 * @param newItem pointer to item to add
 * @returns item replaced
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

/**
 * Replace item from inventory
 * @param newItem pointer to item to add
 * @return item replaced
 */
Item* Character::replaceInventory (Item* newItem, const int& pos) {
    Item* oldItem = (this->_inventory)[pos];
    (this->_inventory)[pos] = newItem;
    return oldItem;
};

/**
 * 
 */
void Character::removeInInventory (const int& pos) {
    (this->_inventory)[pos] = nullptr;
};

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
void Character::_clearBrokenInInventory () {
    for (int i = 0; i < INVENTORY_SIZE; i ++) {
        Item* inventoryItem = (this->_inventory)[i]; // works?
        if (inventoryItem->getDurability() <= 0) {
            (this->_inventory)[i] = nullptr; // delete pointer (DELETE OBJECT???)
        };
    };
};






//------Main methods------//

/**
 * Clear broken items from whole inventory (including armor and weapon slots)
 */
void Character::clearBroken () {
    this->_clearBrokenArmor();
    this->_clearBrokenWeapon();
    this->_clearBrokenInInventory();
};

/**
 * Clear all items from whole inventory (including armor and weapon slots)
 */
void Character::clearAllInventories () {
        this->clearArmor();
        this->clearWeapon();
        this->clearInventory();
    };

/**
 * Update character position
 * @param x x-axis position
 * @param y y-axis position
 */
void Character::updatePosition (const int& x, const int& y) {
    this->_xPos = x;
    this->_yPos = y;
}

/**
 * Update character alive status
 */
void Character::updateStatus () {
    if (this->_health <= 0) {
        this->_alive = false;
    };
};

/**
 * Check character alive status
 * @return alive boolean
 */
bool Character::isAlive () {
    return this->_alive;
};






/**
* TO DO
* class destructor to call when dead
* shield slot (offhand) with activation hotkey for damage reduction
* natural health regeneration?
*/
