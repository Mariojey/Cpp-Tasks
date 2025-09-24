#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

#include "Gen.h"

using namespace std;

unsigned int MAX_WEIGHT = 50;
unsigned int GENOTYPE_LEN = 20;

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

vector<vector<Gen>> rouletteSelection(vector<vector<Gen>> generatedPopulation, vector<GenCandidat> gensEnvironment){

    vector<vector<Gen>> Parents;

    unsigned int maximumPrice = 0;

    for(auto& chromosom : generatedPopulation){
        unsigned int calculatedPrice = chromosomValidation(chromosom, GENOTYPE_LEN, gensEnvironment, MAX_WEIGHT);
        maximumPrice += calculatedPrice;
    }

    unsigned int randomValue = (rand()%maximumPrice);

    unsigned int currentPosInRoulette = 0;
    unsigned int prevPosition = 0;
    for(auto& genotype: generatedPopulation){
        unsigned int calculatedPrice = chromosomValidation(genotype, GENOTYPE_LEN, gensEnvironment, MAX_WEIGHT);
        prevPosition = currentPosInRoulette;
        currentPosInRoulette += calculatedPrice;
        if(currentPosInRoulette > randomValue){
            Parents.push_back(genotype);
            break;
        }
    }

    //Add Second Parent
    unsigned int secRandomValue = (rand()%maximumPrice);
    while ((secRandomValue != randomValue) && (prevPosition < secRandomValue && secRandomValue < currentPosInRoulette))
    {
        secRandomValue = (rand()%maximumPrice);
    }

    currentPosInRoulette = 0;
    for(auto& genotype: generatedPopulation){
        unsigned int calculatedPrice = chromosomValidation(genotype, GENOTYPE_LEN, gensEnvironment, MAX_WEIGHT);
        currentPosInRoulette += calculatedPrice;
        if(currentPosInRoulette > secRandomValue){
            Parents.push_back(genotype);
            break;
        }
    }
    
    return Parents;
    
}

int main(){

    srand((unsigned)time(0));

    vector<vector<Gen>> generatedPopulation = generatePopulation(10, GENOTYPE_LEN);
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
        unsigned int calcualtedPrice = chromosomValidation(chromosom, GENOTYPE_LEN, gensEnvironment, MAX_WEIGHT);
        cout<<calcualtedPrice<<endl;
    }

    vector<vector<Gen>> selectedParents = rouletteSelection(generatedPopulation, gensEnvironment);
    
    for (auto& genotype: selectedParents)
    {
        unsigned int calculatedPrice = chromosomValidation(genotype, GENOTYPE_LEN, gensEnvironment, MAX_WEIGHT);
        cout<<calculatedPrice<<" - ";
        for (auto& fenotype: genotype)
        {
            cout<<fenotype.getAllel();
        }
        cout<<endl;
    }
    
    

    return 0;
}