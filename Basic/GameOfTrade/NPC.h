#include  <iostream>
#include <vector>
#include <fstream>

#include "Item.h"

using namespace std;

class AbstractNPC{
    virtual void WelcomeClient() = 0;
};

class NPC: AbstractNPC{
    
private:
    string Name;

protected:
    int Money;

public:

    void setName(string name);
    string getName();

    void setMoney(int money);
    int getMoney();

    NPC(string name, int money);

    void WelcomeClient();
};

class Inkeeper:public NPC{
    
    public:
        vector<Item> Items;

        Inkeeper(string name, int money, vector<Item> items);

        void ShowItems();

};