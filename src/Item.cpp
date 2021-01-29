#include "Item.h"

Item::Item(string item) {
    // Read JSON
    ifstream fileInfoItem("assets/items/" + item, ifstream::binary);
    Json::Value infoItem;
    fileInfoItem >> infoItem;
    
    // Init attributes
    this->_object = infoItem["object"].asInt();
    this->_name = infoItem["name"].asString();
    this->_description = infoItem["description"].asString();
    this->_icon = infoItem["icon"].asInt();
    this->_type = infoItem["type"].asInt();
    this->_value = infoItem["value"].asInt();
    this->_durability = infoItem["durability"].asInt();
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