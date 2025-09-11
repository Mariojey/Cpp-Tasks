#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

#include "Gen.h"

using namespace std;

unsigned int MAX_WEIGHT = 12;

vector<GenCandidat> loadGensFromFile(const string& filename){

    vector<GenCandidat> gens;
    ifstream file(filename);

    if(!file.is_open()){
        cerr<<"Required file is unavailable!"<<endl;
        return gens;
    }

    unsigned int id;
    unsigned int price;
    unsigned int weight;

    while(file >> id >> price >> weight){
        gens.emplace_back(id, price, weight);
    }
    
    file.close();
    return gens;
}

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

unsigned int chromosomValidation(vector<Gen> chromosom, int chromosomSize, vector<GenCandidat> potentialGens, unsigned int maxWeight){

    unsigned int sumWeight = 0;
    unsigned int sumPrice = 0;

    for (int i = 0; i < chromosomSize; i++)
    {
        Gen current = chromosom[i];

        if(current.getAllel() == true){
            sumWeight += potentialGens[i].getWeight();
            sumPrice += potentialGens[i].getPrice();
        }

        if(sumWeight > maxWeight){
            return 0;
        }
    }

    return sumPrice;

}

int main(){

    srand((unsigned)time(0));

    vector<vector<Gen>> generatedPopulation = generatePopulation(10, 8);
    vector<GenCandidat> gensEnvironment = loadGensFromFile("stats.txt");

    for (auto& chromosom : generatedPopulation)
    {
        for(auto& fenotype : chromosom){
            cout<<fenotype.getAllel();
        }
        cout<<endl;
    }

    for (auto& chromosom : generatedPopulation)
    {
        unsigned int calcualtedPrice = chromosomValidation(chromosom, 8, gensEnvironment, MAX_WEIGHT);
        cout<<calcualtedPrice<<endl;
    }
    
    

    return 0;
}