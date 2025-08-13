#include  <iostream>

using namespace std;

class AbstractNPC{
    virtual void WelcomeClient();
};

class NPC: AbstractNPC{
    
private:
    string Name;

protected:
    string Job;

public:

    void setName(string name);
    string getName();

    void setJob(string job);
    string getJob();

    NPC(string name, string job);

    void WelcomeClient();
};