#include <iostream>

using namespace std;

enum EItemType {
    FOOD,
    DRINK,
    MEDICINE,
    ARMOR
};

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