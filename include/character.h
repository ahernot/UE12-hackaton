#include <vector>

class Item {};
class ArmorItem {};
class WeaponItem {};


class Character {

    public:
        Character (const int& _type, const int& x, const int& y, const int& health, const int& inventorySlots);
        // inventorySlots default is 4
        // health default is 99


        

        //int[] getCoordinates ();
        //int getType ();


        // Armor management
        int getArmorVal (); // get armor protection value
        ArmorItem replaceArmor (const ArmorItem* newArmor); // outputs the previous armor item

        // Weapon management
        int getWeaponVal ();
        WeaponItem replaceWeapon (const WeaponItem* newWeapon); // outputs the previous weapon item


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
        void move (const int& x, const int& y); // move character


    protected:

        // bool isDead; ???

        // Character type
        int _type;

        // Position
        int _xPos;
        int _yPos;

        // Health
        int _health; // value between 0 and 99?

        // Armor pieces
        std::vector<ArmorItem> _armor(4); // vector of size 4

        // Weapon
        WeaponItem* _weapon;

        // Inventory
        std::vector<Item*> _inventory; // inventory size?


}