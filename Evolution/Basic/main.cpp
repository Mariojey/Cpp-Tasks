#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Gen.h"

using namespace std;

vector<vector<Gen>> generatePopulation(int populationSize, int chromosomSize){
    
    vector<vector<Gen>> population;

    for (int i = 0; i < populationSize; i++)
    {
        vector<Gen> chromosom;
        
        for(int j = 0; j < chromosomSize; j++){
            
            int randomValue = (rand()%2);

            if(randomValue == 0){
                chromosom.emplace_back(false);
            }else if(randomValue == 1){
                chromosom.emplace_back(true);
            }
        }

        population.push_back(chromosom);
    }

    return population;
    
}

int main(){

    srand((unsigned)time(0));

    vector<vector<Gen>> generatedPopulation = generatePopulation(10, 8);

    for (auto& chromosom : generatedPopulation)
    {
        for(auto& fenotype : chromosom){
            cout<<fenotype.getAllel();
        }
        cout<<endl;
    }
    

    return 0;
}