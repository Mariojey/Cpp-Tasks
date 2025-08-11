#include <iostream>
#include "question.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void Question::read(){
    
    fstream file;
    file.open("quiz.txt", ios::in);

    if(file.good() == false){
        cout<<"Nie udało się otworzyć pliku!"<<endl;
        exit(0);
    }

    int line_nr=(question_nr-1)*6+1;
    int actual_nr=1;

    string line;

    while(getline(file, line)){
        
        if(actual_nr==line_nr){
            text=line;
        }
        if(actual_nr==line_nr+1){
            a=line;
        }
        if(actual_nr==line_nr+2){
            b=line;
        }
        if(actual_nr==line_nr+3){
            c=line;
        }
        if(actual_nr==line_nr+4){
            d=line;
        }
        if(actual_nr==line_nr+5){
            correct=line;
        }
        actual_nr++;
    }

    file.close();
}

void Question::ask(){
    cout<<endl<<text<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<"---------------------"<<endl;
    cin>>answer;
}

void Question::check(){
    if(answer==correct){
        result=1;
    }else{
        result=0;
    }
}
