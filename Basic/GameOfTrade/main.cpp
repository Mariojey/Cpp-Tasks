#include <iostream>
#include "NPC.h"

using namespace std;

int main(){
    
    NPC Butcher = NPC("Rudolf", "Butcher");
    NPC Smith = NPC("Rumpel", "Smith");

    cout<<Butcher.getName()<<endl;
    cout<<Smith.getJob()<<endl;

    Butcher.WelcomeClient();
    Smith.WelcomeClient();

    return 0;
}