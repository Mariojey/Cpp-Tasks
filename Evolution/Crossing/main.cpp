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

    for (auto& genotype: sortedGenotypes)
    {
        prevPosition = currentPosInRoulette;
        currentPosInRoulette += iterator;

        iterator--;

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

vector<vector<Gen>> pointCrossing(vector<vector<Gen>> givenParents, vector<GenCandidat> gensEnvironment){

    vector<vector<Gen>> childrens;

    vector<Gen> firstChild;
    vector<Gen> secondChild;

    for (int i = 0; i < GENOTYPE_LEN; i=i+2)
    {
        firstChild.push_back(givenParents[0][i]);
        firstChild.push_back(givenParents[1][i+1]);

        secondChild.push_back(givenParents[1][i]);
        secondChild.push_back(givenParents[0][i+1]);

    }

    int firstChildPrice = chromosomValidation(firstChild, GENOTYPE_LEN, gensEnvironment, MAX_WEIGHT);
    int secondChildPrice = chromosomValidation(secondChild, GENOTYPE_LEN, gensEnvironment, MAX_WEIGHT);

    int iterationJump = 2;

    while (firstChildPrice == 0 && secondChildPrice == 0 && iterationJump < GENOTYPE_LEN/2)
    {
        firstChild.clear();
        secondChild.clear();

        int iterator = 0;
        while (iterator < GENOTYPE_LEN)
        {
            for (int subIterator = 0; subIterator < iterationJump; subIterator++)
            {
                if(iterator < GENOTYPE_LEN){
                    firstChild.push_back(givenParents[0][iterator]);
                    secondChild.push_back(givenParents[1][iterator]);
                    iterator++;
                }
            }

            for (int subIterator = 0; subIterator < iterationJump; subIterator++)
            {
                if(iterator < GENOTYPE_LEN){
                    firstChild.push_back(givenParents[1][iterator]);
                    secondChild.push_back(givenParents[0][iterator]);
                    iterator++;
                }
            }
            
        }

        firstChildPrice = chromosomValidation(firstChild, GENOTYPE_LEN, gensEnvironment, MAX_WEIGHT);
        secondChildPrice = chromosomValidation(secondChild, GENOTYPE_LEN, gensEnvironment, MAX_WEIGHT);

        iterationJump++;
    }

    childrens.push_back(firstChild);
    childrens.push_back(secondChild);
    
    return childrens;
    
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

    //DO przetestowania generowanie funkcją pointCrossing
    

    return 0;
}