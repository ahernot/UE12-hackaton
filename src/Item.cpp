#include "Item.h"

Item::Item(string& item) {
    // Read JSON
    ifstream fileInfoItem("assets/items/" + item);
    Json::value infoItem;
    fileInfoItem >> infoItem;
    
    // Init attributes
    this->_object = infoItem["object"];
    this->_name = infoItem["name"];
    this->_description = infoItem["description"];
    this->_icon = infoItem["icon"];
    this->_type = infoItem["type"];
    this->_value = infoItem["value"];
    this->_durability = infoItem["durability"];
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