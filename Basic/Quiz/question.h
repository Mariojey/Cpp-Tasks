#include <iostream>

using namespace std;

class Question{

public:

    string text;
    string a, b, c, d;

    int question_nr;
    string correct;
    string answer;

    int result;

    void read();
    void ask();
    void check();
};