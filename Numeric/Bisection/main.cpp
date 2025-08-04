#include <iostream>
#include <cmath>

using namespace std;

float function_value(float x){
    
    //FUNCTION IMPLEMENTATION
    return (x-4); 
}

int main(int argc, char * argv[]){
    
    if (argc != 4)
    {
        cout<<"Missing arguments"<<endl;
        return 1;
    };

    if (signbit(function_value((float)atoi(argv[1]))) == signbit(function_value((float)atoi(argv[2]))))
    {
        cout<<function_value((float)atoi(argv[1]))<<endl;
        cout<<function_value((float)atoi(argv[2]))<<endl;
        cout<<"No roots"<<endl;
        return 0;
    };

    float span = (float)atoi(argv[2]) - (float)atoi(argv[1]);
    float a = (float)atoi(argv[1]);
    float b = (float)atoi(argv[2]);

    for (int i = 0; i < atoi(argv[3]); i++)
    {
        span = span/2.0;
        float c = a + span;

        if ((abs(span)<0.00001) || (abs(function_value(c)) < 0.00001))
        {
            cout<<"Result: "<<endl;
            cout<<"i "<<i<<endl;
            cout<<"c "<<c<<endl;
            cout<<"f(c) "<<function_value(c)<<endl;

            return 0;
        }

        if(signbit(function_value(c)) != signbit(function_value(a))){
            b = c;
        }else{
            a = c;
        }

        
    }    

    return 0;
}