#include <iostream>

using namespace std;

#ifndef GEN_H
#define GEN_H

class Gen{
    private:
        bool Allel;
    public:
        void setAllel(bool allel);
        bool getAllel();

        Gen(bool allel);
};

#endif

#ifndef GEN_CANDIDAT_H
#define GEN_CANDIDAT_H

class GenCandidat{
    
    private:
        unsigned int Id;
        unsigned int Price;
        unsigned int Weight;
    public:
        void setId(unsigned int id);
        void setPrice(unsigned int price);
        void setWeight(unsigned int weight);

        unsigned int getId();
        unsigned int getPrice();
        unsigned int getWeight();

        GenCandidat(unsigned int id, unsigned int price, unsigned int weight);
};

#endif