#include <iostream>
#include "NPC.h"

using namespace std;

void NPC::setName(string name){
    Name = name;
}

string NPC::getName(){
    return Name;
}

void NPC::setJob(string job){
    Job = job;
}

string NPC::getJob(){
    return Job;
}

NPC::NPC(string name, string job)
    : Name(name), Job(job) {}

void NPC::WelcomeClient(){
    cout<<"Witaj u "<<Job<<endl<<",czym mogę służyć!"<<endl;
}