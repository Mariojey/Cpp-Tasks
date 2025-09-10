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