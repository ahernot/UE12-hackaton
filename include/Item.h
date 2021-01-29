#ifndef _ITEM_H_
#define _ITEM_H_

#include <iostream>
#include <array>
#include <fstream>
#include <json/value.h>

using namespace std;

class Item {
    protected:
        int _object;
        string _name;
        string _description;
        char _icon;
        int _type;
        int _value;
        int _durability;

    public:
        Item(string& item = "generic");
        ~Item();
        virtual void print();
        char getIcon();
        int getType();
        int getDurability();
};

#endif