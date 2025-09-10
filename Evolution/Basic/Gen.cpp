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