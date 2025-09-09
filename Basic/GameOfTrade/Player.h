#include <iostream>
#include <vector>
#include <fstream>

#include "Item.h"

using namespace std;

class AbstractPlayer{
    virtual void Welcome() = 0;
};

class Player: AbstractPlayer{

    private:
        string Name;

    protected:
        int Money;

    public:
        vector<Item> Equipment;

        void setName(string name);
        string getName();

        void setMoney(int money);
        int getMoney();

        Player(string name, int money, vector<Item> items);

        void Welcome();

        void ShowItems();
};