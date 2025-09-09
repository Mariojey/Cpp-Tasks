#include <iostream>

using namespace std;

#ifndef ITEM_TYPE_H
#define ITEM_TYPE_H

enum EItemType {
    FOOD,
    DRINK,
    MEDICINE,
    ARMOR
};
#endif

#ifndef ITEM_H
#define ITEM_H

class Item{

    private:

        string Name;
        EItemType Type;
        int Price;

    public:

        void setName(string name);
        string getName();

        void setType(EItemType type);
        EItemType getType();

        void setPrice(int price);
        int getPrice();

        Item(string name, EItemType type, int price);
        
};

#endif