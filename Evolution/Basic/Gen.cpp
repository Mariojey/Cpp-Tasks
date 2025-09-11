#include <iostream>
#include "Gen.h"

using namespace std;

void Gen::setAllel(bool allel){
    Allel = allel;
}

bool Gen::getAllel(){
    return Allel;
}

Gen::Gen(bool allel)
    : Allel(allel) {}

void GenCandidat::setId(unsigned int id){
    Id = id;
}

void GenCandidat::setPrice(unsigned int price){
    Price = price;
}

void GenCandidat::setWeight(unsigned int weight){
    Weight = weight;
}

unsigned int GenCandidat::getId(){
    return Id;
}

unsigned int GenCandidat::getPrice(){
    return Price;
}

unsigned int GenCandidat::getWeight(){
    return Weight;
}

GenCandidat::GenCandidat(unsigned int id, unsigned int price, unsigned int weight)
    : Id(id), Price(price), Weight(weight) {}