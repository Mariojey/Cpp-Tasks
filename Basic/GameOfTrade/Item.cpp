#include <iostream>
#include "Item.h"

using namespace std;

void Item::setName(string name){
    Name = name;
}

string Item::getName() {
    return Name;
}

void Item::setType(EItemType type){
    Type = type;
}

EItemType Item::getType(){
    return Type;
}

void Item::setPrice(int price){
    Price = price;
}

int Item::getPrice(){
    return Price;
}

Item::Item(string name, EItemType type, int price)
    : Name(name), Type(type), Price(price) {}