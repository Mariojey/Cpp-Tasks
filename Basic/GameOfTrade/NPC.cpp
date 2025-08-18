#include <iostream>
#include <vector>
#include "NPC.h"

using namespace std;

void NPC::setName(string name){
    Name = name;
}

string NPC::getName(){
    return Name;
}

void NPC::setMoney(int money){
    Money = money;
}

int NPC::getMoney(){
    return Money;
}

NPC::NPC(string name, int money)
    : Name(name), Money(money) {}

void NPC::WelcomeClient(){
    cout<<"Witaj! "<<endl<<",czym mogę służyć!"<<endl;
}

Inkeeper::Inkeeper(string name, int money, vector<Item> items)
    :NPC::NPC(name, money){
        Items = items;
    };

void Inkeeper::ShowItems(){
    for(auto& it : Items){
        cout<<it.getName()<< " "<<it.getType()<< " "<<it.getPrice()<<endl;
    }
}