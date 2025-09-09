#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

void Player::setName(string name){
    Name = name;
}

string Player::getName(){
    return Name;
}

void Player::setMoney(int money){
    Money = money;
}

int Player::getMoney(){
    return Money;
}

Player::Player(string name, int money, vector<Item> items)
    : Name(name), Money(money), Equipment(items) {}

