#include <iostream>
#include <math.h>

using namespace std;

#define SIZE_ROW 5
#define SIZE_COL 5

typedef pair<int, int> Cell; //-One Cell in Grid

struct Node {

    int x_of_parent;
    int y_of_parent;

    double f, g, h;
};

double calculateValueOfH(int row, int col, Cell goal){

    int x_utils = row - goal.first;
    int y_utils = col - goal.second;

    return ((double)sqrt((x_utils * x_utils) + (y_utils * y_utils)));

}

void aStar(int grid[][SIZE_COL], Cell source, Cell goal){

    if (source.first == goal.first && source.second == goal.second)
    {
        
        cout<< "Goal gained! At start!"<<endl;
        return;
    }

    if(source.first < 0 || source.second < 0 || source.first >= SIZE_ROW || source.second >= SIZE_COL){
        
        cout<< "Source is unavailable"<<endl;
        return;

    }
    
    if(goal.first < 0 || goal.second < 0 || goal.first >= SIZE_ROW || goal.second >= SIZE_COL){
        
        cout<< "Goal is unavailable"<<endl;
        return;

    }

    if (grid[source.first][source.second] == 1)
    {
        
        cout<< "Source is blocked"<<endl;
        return;
    }
    
    if (grid[goal.first][goal.second] == 1)
    {
        
        cout<< "Goal is blocked"<<endl;
        return;
    }


    bool closedList[SIZE_ROW][SIZE_COL]; 

    for (int i = 0; i < SIZE_ROW; i++)
    {
        for (int j = 0; j < SIZE_COL; j++)
        {
            closedList[SIZE_ROW][SIZE_COL] = false;
        }
        
    }

    Node cellsWithHeurystics[SIZE_ROW][SIZE_COL];

    //Blank this array
    for (int i = 0; i < SIZE_ROW; i++)
    {
        for (int j = 0; j < SIZE_COL; j++)
        {
            
        }
        
    }
    
    
}

int main(){


    
    return 0;
}