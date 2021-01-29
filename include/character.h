#include <array>

class Item {};
class ArmorItem {
    public:
        int getDefensePoints() {return 0;};
        int getType() {return 0;};
};
class WeaponItem {
    public:
        int getAttackPoints() {return 0;};
};


class Character {

    public:
        Character (const int& _type, const int& x, const int& y, const int& health, const int& inventorySlots);
        // inventorySlots default is 4
        // health default is 99

        // Stats
        std::array<int, 2> getCoordinates (); // return int coordinates []??
        int getType (); // return character type (0=player)


        // Armor management
        int getArmorVal (); // get armor protection value
        ArmorItem* replaceArmor (ArmorItem* newArmor); // outputs the previous armor item
        ArmorItem* getArmorItem (const int& pos);

        // Weapon management
        int getWeaponVal (); // get weapon damage value
        WeaponItem* replaceWeapon (WeaponItem* newWeapon); // outputs the previous weapon item
        WeaponItem* getWeaponItem ();

        // Health management
        int getHealth (); // return character health
        int addHealth (const int& healthToAdd);
        int removeHealth (const int& healthToRemove);

        // Inventory management
        std::vector<Item*> getInventory(); // return whole inventory
        Item getInventory (const int& pos); // return specific item from inventory
        Item replaceInventory (const Item* itemToAdd); // englobe tous les types d'Item ?
        Item replaceInventory (const Item* itemToAdd, const int& pos);
        void removeInInventory (const int& pos); // delete if broken, with isBroken method from Item

        // Global loop functions
        void cleanBroken (); // remove broken items in inventory, weapon slot, and armor slots
        //void move (const int& x, const int& y); // move character
        void updatePosition (const int& x, const int& y); // update character position


    protected:

        // bool isDead; ???
        int _inventorySlots; // remove

        // Character type
        int _type;

        // Position
        int _xPos;
        int _yPos;

        // Health
        int _health; // value between 0 and 100

        // Armor pieces
        std::array<ArmorItem*, 4> _armor; // vector of size 4

        // Weapon
        WeaponItem* _weapon;

        // Inventory
        std::array<Item*, this->_inventorySlots> _inventory;

}