#include <iostream>
#include <vector>   
#include <fstream>

#include "NPC.h"

using namespace std;

vector<Item> loadItemsFromFile(const string& filename){
    
    vector<Item> items;
    ifstream file(filename);

    if(!file.is_open()){
        cerr<<"Karczma zamknięta, nie znaleziono klucza do magazynu!"<<endl;
        return items;
    }

    string name;
    int typeInt;
    int price;

    while(file >> name >> typeInt >> price){
        items.emplace_back(name, static_cast<EItemType>(typeInt), price);
    }

    file.close();
    return items;
}

vector<Item> loadPlayerEquipment(const string& filename, int * playerMoney){

    vector<Item> items;
    ifstream file(filename);

    if(!file.is_open()){
        cerr<<"Zgubiłeś plecak"<<endl;
        return items;
    }

    string name;
    int typeInt;
    int price;
    int money;

    while(file >> name >> typeInt >> price >> money){
        items.emplace_back(name, static_cast<EItemType>(typeInt), price);
        * playerMoney = money;
    }

    file.close();
    return items;
}

int main(){

    int playerMoney = 0;
    vector<Item> playerEquipment = loadPlayerEquipment("player.txt", &playerMoney);
    
    vector<Item> loadedInkeeperItems = loadItemsFromFile("inkeeper.txt");

    Inkeeper John = Inkeeper("John", 20, loadedInkeeperItems);
    John.ShowItems();
    cout<<playerMoney<<endl;

    return 0;
}