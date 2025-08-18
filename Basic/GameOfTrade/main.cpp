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

int main(){
    
    vector<Item> loadedInkeeperItems = loadItemsFromFile("inkeeper.txt");

    Inkeeper John = Inkeeper("John", 20, loadedInkeeperItems);
    John.ShowItems();

    return 0;
}