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
        Character (const int& type, const int& x, const int& y, int health=DEFAULT_HEALTH, int baseAttackVal=BASE_ATTACK_VALUE, int baseArmorVal=BASE_ARMOR_VALUE);
        ~Character();

        // Stats
        std::array<int, 2> getCoordinates ();
        int getType (); // return character type (0=player)


        // Armor management
        int getArmorVal (); // get armor protection value
        ArmorItem* replaceArmor (ArmorItem* newArmor); // outputs the previous armor item
        ArmorItem* getArmorItem (const int& pos);
        void clearArmor ();
        void clearBrokenArmor ();

        // Weapon management
        int getWeaponVal (); // get weapon damage value
        WeaponItem* replaceWeapon (WeaponItem* newWeapon); // outputs the previous weapon item
        WeaponItem* getWeaponItem ();
        void clearWeapon ();
        void clearBrokenWeapon ();

        // Health management
        int getHealth (); // return character health
        int addHealth (const int& healthToAdd);
        int removeHealth (const int& healthToRemove);
        void clearHealth ();

        // Inventory management
        std::array<Item*, INVENTORY_SIZE> getInventory(); // return whole inventory
        Item* getInventory (const int& pos); // return specific item from inventory
        Item* replaceInventory (Item* newItem); // englobe tous les types d'Item ?
        Item* replaceInventory (Item* newItem, const int& pos);
        void removeInInventory (const int& pos); // delete if broken, with isBroken method from Item
        void clearInventory ();
        void clearBrokenInInventory();

        // Clear all items
        void clearAllInventories ();

        // Global loop functions
        void clearBroken (); // remove broken items in inventory, weapon slot, and armor slots
        void updatePosition (const int& x, const int& y); // update character position
        void updateStatus (); // alive or dead

        bool isAlive ();


    protected:

        bool _alive;

        // Character type
        int _type;

        // Position
        int _xPos;
        int _yPos;

        // Base stats
        int _baseAttackVal;
        int _baseArmorVal;

        // Health
        int _health; // value between 0 and 100

        // Armor pieces
        std::array<ArmorItem*, 4> _armor;

        // Weapon
        WeaponItem* _weapon;

        // Inventory
        std::array<Item*, INVENTORY_SIZE> _inventory;

};

#endif