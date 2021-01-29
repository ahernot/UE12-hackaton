#include "Item.h"

Item::Item(string item) {
    // Read JSON
    ifstream infoItem("assets/items/" + item);
    json j;
    infoItem >> j;

    this->_object = j["object"].get<int>();
    this->_name = j["name"].get<string>();
    this->_description = j["description"].get<string>();
    this->_icon = j["icon"].get<char>();
    this->_type = j["type"].get<int>();
    this->_value = j["value"].get<int>();
    this->_durability = j["durability"].get<int>();

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