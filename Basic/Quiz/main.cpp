#include <iostream>
#include "question.h"

using namespace std;

int main(){
    
    Question q[3];
    int sum=0;

    for (int i = 0; i < 3; i++)
    {
        q[i].question_nr = i+1;
        q[i].read();
        q[i].ask();
        q[i].check();
        sum += q[i].result;
    }

    
    return 0;

}