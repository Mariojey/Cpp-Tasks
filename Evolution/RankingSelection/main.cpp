#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>

#include "Gen.h"

using namespace std;

unsigned int MAX_WEIGHT = 50;
unsigned int GENOTYPE_LEN = 20;
unsigned int POPULATION_SIZE = 20;

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

    while (file >> id >> price >> weight)
    {
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

vector<vector<Gen>> rankingSelection(vector<vector<Gen>> generatedPopulation, vector<GenCandidat> gensEnvironment){

    vector<vector<Gen>> Parents;

    unsigned int maximumPrice = 0;
    for (int i = POPULATION_SIZE; i > 0; i--)
    {
        maximumPrice += i;
    }

    vector<vector<Gen>> sortedGenotypes = generatedPopulation;

    sort(sortedGenotypes.begin(), sortedGenotypes.end(),
        [&](const vector<Gen>& a, const vector<Gen>& b) {
        unsigned int priceA = chromosomValidation(a, a.size(), gensEnvironment, MAX_WEIGHT);
        unsigned int priceB = chromosomValidation(b, b.size(), gensEnvironment, MAX_WEIGHT);
        return priceA > priceB; // malejąco
    });

    
    unsigned int randomValue = (rand()%maximumPrice);

    unsigned int currentPosInRoulette = 0;
    unsigned int prevPosition = 0;
    unsigned int iterator = POPULATION_SIZE;

    cout<<"Random Value: "<<randomValue<<endl;

    for (auto& genotype: sortedGenotypes)
    {
        prevPosition = currentPosInRoulette;
        currentPosInRoulette += iterator;

        iterator--;

        cout<<"Aktualna pozycja: "<<currentPosInRoulette<<endl;

        if(currentPosInRoulette > randomValue){
            Parents.push_back(genotype);
            break;
        }
    }

    //Add Second Parent
    unsigned int secRandomValue = (rand()%maximumPrice);

    while ((secRandomValue == randomValue) || (prevPosition < secRandomValue && secRandomValue < currentPosInRoulette)){
        secRandomValue = (rand()%maximumPrice);
    }

    iterator = POPULATION_SIZE;
    currentPosInRoulette = 0;
    for (auto& genotype : sortedGenotypes)
    {
        currentPosInRoulette += iterator;
        iterator--;

        if(currentPosInRoulette > secRandomValue){
            Parents.push_back(genotype);
            break;
        }
    }
    
    return Parents;

}

int main(){

    srand((unsigned)time(0));

    vector<vector<Gen>> generatedPopulation = generatePopulation(POPULATION_SIZE, GENOTYPE_LEN);
    vector<GenCandidat> gensEnvironment = loadGensFromFile("stats.txt");

    cout<<"Parents debugging"<<endl;
    
    vector<vector<Gen>> selectedParents = rankingSelection(generatedPopulation, gensEnvironment);
    
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