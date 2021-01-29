#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <array>
#include <vector>
#include "config.h"
#include "ArmorItem.h"
#include "HealItem.h"
#include "WeaponItem.h"


class Character {

    public:
        // Class constructor
        Character (const int& type, const int& x, const int& y, int health=DEFAULT_HEALTH, int baseAttackVal=BASE_ATTACK_VALUE, int baseArmorVal=BASE_ARMOR_VALUE);
        // Class destructor
        ~Character();

        // Stats
        std::array<int, 2> getCoordinates ();
        int getType ();

        // Armor management
        int getArmorVal ();
        ArmorItem* replaceArmor (ArmorItem* newArmor);
        ArmorItem* getArmorItem (const int& pos);
        void clearArmor ();
        void clearBrokenArmor ();

        // Weapon management
        int getWeaponVal ();
        WeaponItem* replaceWeapon (WeaponItem* newWeapon);
        WeaponItem* getWeaponItem ();
        void clearWeapon ();
        void clearBrokenWeapon ();

        // Health management
        int getHealth ();
        int addHealth (const int& healthToAdd);
        int removeHealth (const int& healthToRemove);
        void clearHealth ();

        // Inventory management
        std::array<Item*, INVENTORY_SIZE> getInventory();
        Item* getInventory (const int& pos);
        Item* replaceInventory (Item* newItem);
        Item* replaceInventory (Item* newItem, const int& pos);
        void removeInInventory (const int& pos);
        void clearInventory ();
        void clearBrokenInInventory();

        // Clear all items
        void clearAllInventories ();

        // Main loop functions
        void clearBroken (); // remove broken items in inventory, weapon slot, and armor slots
        void updateStatus (); // check if dead (HP=0)

        // Update 2D position coordinates
        void updatePosition (const int& x, const int& y);

        // Alive status
        bool isAlive ();


    protected:

        // Alive status
        bool _alive;

        // Character type
        int _type;

        // Position
        int _xPos;
        int _yPos;

        // Stats
        int _baseAttackVal; // Naked attack value
        int _baseArmorVal; // Naked armor protection value
        int _health; // Health attribute (value between 0 and 100)

        // Items
        std::array<ArmorItem*, 4> _armor; // Armor pieces
        WeaponItem* _weapon; // Weapon
        std::array<Item*, INVENTORY_SIZE> _inventory; // Inventory

};

#endif
