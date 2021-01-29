#include "Item.h"

Item::Item(string item) {
    // Read JSON
    ifstream infoItem("assets/items/" + item);

    infoItem >> this->_object;
    infoItem >> this->_name;
    infoItem >> this->_description;
    infoItem >> this->_icon;
    infoItem >> this->_type;
    infoItem >> this->_value;
    infoItem >> this->_durability;
    
    /* // Init attributes
    this->_object = infoItem["object"].asInt();
    this->_name = infoItem["name"].asString();
    this->_description = infoItem["description"].asString();
    this->_icon = infoItem["icon"].asInt();
    this->_type = infoItem["type"].asInt();
    this->_value = infoItem["value"].asInt();
    this->_durability = infoItem["durability"].asInt(); */
    infoItem.close();
}

void Item::print() {
    cout << this->_name << endl;
    cout << this->_description << endl;
}

char Item::getIcon() {
    return this->_icon;
}

int Item::getType() {
    return this->_type;
}

int Item::getDurability() {
    return this->_durability;
}