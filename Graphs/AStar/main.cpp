#include <iostream>
#include <math.h>
#include <set>
#include <stack>

using namespace std;

#define SIZE_ROW 5
#define SIZE_COL 5

typedef pair<int, int> Cell; //-One Cell in Grid

struct Node {

    int x_of_parent;
    int y_of_parent;

    double f, g, h;
};

typedef pair<double, pair<int, int>> CellWithHeurystics;

double calculateValueOfH(int row, int col, Cell goal){

    int x_utils = row - goal.first;
    int y_utils = col - goal.second;

    return ((double)sqrt((x_utils * x_utils) + (y_utils * y_utils)));

}

void printPath(Node cellsWithHeurystics[][SIZE_COL], Cell goal){

    int row = goal.first;
    int col = goal.second;

    stack<Cell> Path;

    while (!(cellsWithHeurystics[row][col].x_of_parent == row
            && cellsWithHeurystics[row][col].y_of_parent == col
    ))
    {
        Path.push(make_pair(row, col));

        int temp_row = cellsWithHeurystics[row][col].x_of_parent;
        int temp_col = cellsWithHeurystics[row][col].y_of_parent;

        row = temp_row;
        col = temp_col;
    }

    Path.push(make_pair(row, col));

    while(!Path.empty()){
        pair<int, int> p = Path.top();
        Path.pop();
        cout<<"| "<<p.first<<","<<p.second<<" |"<<endl;
    }

    return;
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
            cellsWithHeurystics[i][j].x_of_parent = -1;
            cellsWithHeurystics[i][j].y_of_parent = -1;
            cellsWithHeurystics[i][j].g = __FLT_MAX__;
            cellsWithHeurystics[i][j].f = __FLT_MAX__;
            cellsWithHeurystics[i][j].h = __FLT_MAX__;
        }
    }

    cellsWithHeurystics[source.first][source.second].x_of_parent = source.first;
    cellsWithHeurystics[source.first][source.second].y_of_parent = source.second;

    cellsWithHeurystics[source.first][source.second].f = 0.0;
    cellsWithHeurystics[source.first][source.second].g = 0.0;
    cellsWithHeurystics[source.first][source.second].h = 0.0;

    set<CellWithHeurystics> openList;

    openList.insert(make_pair(0.0, make_pair(source.first, source.second)));

    bool gainedGoal = false;

    while (!openList.empty())
    {
        
        CellWithHeurystics point = *openList.begin();

        openList.erase(openList.begin());

        closedList[point.second.first][point.second.second] = true;

        int x = point.second.first;
        int y = point.second.second;

        double gNew;
        double hNew;
        double fNew;

        /*
        0?0
        0X0
        000
        */
        if (x-1 >= 0 && x <SIZE_ROW && y >= 0 && y<SIZE_COL)
        {
            if((x-1)==goal.first && y == goal.second){
                
                cellsWithHeurystics[x-1][y].x_of_parent = x;
                cellsWithHeurystics[x-1][y].y_of_parent = y;

                cout<<"Lady's and Gentelmen, we got him!"<<endl;

                gainedGoal = true;
                return;
            }
        }
        
    }
    
    
}

int main(){


    
    return 0;
}