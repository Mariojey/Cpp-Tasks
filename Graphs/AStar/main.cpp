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

                printPath(cellsWithHeurystics, goal);
                return;
            }else if(closedList[x - 1][y] == false && grid[x-1][y] == true){
                gNew = cellsWithHeurystics[x][y].g + 1.0;
                hNew = calculateValueOfH(x - 1, y, goal);
                fNew = gNew + hNew;

                if(cellsWithHeurystics[x-1][y].f == __FLT_MAX__ || cellsWithHeurystics[x - 1][y].f > fNew){
                
                    openList.insert(make_pair(fNew, make_pair(x - 1, y)));

                    cellsWithHeurystics[x - 1][y].f = fNew;
                    cellsWithHeurystics[x - 1][y].g = gNew;
                    cellsWithHeurystics[x - 1][y].h = hNew;
                    cellsWithHeurystics[x - 1][y].x_of_parent = x;
                    cellsWithHeurystics[x - 1][y].y_of_parent = y;

                }
            }
        }

        /*
        000
        0X0
        0?0
        */

        if (x+1 >= 0 && x+1 <SIZE_ROW && y >= 0 && y<SIZE_COL)
        {
            if((x+1)==goal.first && y == goal.second){
                
                cellsWithHeurystics[x+1][y].x_of_parent = x;
                cellsWithHeurystics[x+1][y].y_of_parent = y;

                cout<<"Lady's and Gentelmen, we got him!"<<endl;

                gainedGoal = true;

                printPath(cellsWithHeurystics, goal);

                return;
            }else if(closedList[x + 1][y] == false && grid[x+1][y] == true){
                gNew = cellsWithHeurystics[x][y].g + 1.0;
                hNew = calculateValueOfH(x + 1, y, goal);
                fNew = gNew + hNew;

                if(cellsWithHeurystics[x+1][y].f == __FLT_MAX__ || cellsWithHeurystics[x + 1][y].f > fNew){
                
                    openList.insert(make_pair(fNew, make_pair(x + 1, y)));

                    cellsWithHeurystics[x + 1][y].f = fNew;
                    cellsWithHeurystics[x + 1][y].g = gNew;
                    cellsWithHeurystics[x + 1][y].h = hNew;
                    cellsWithHeurystics[x + 1][y].x_of_parent = x;
                    cellsWithHeurystics[x + 1][y].y_of_parent = y;

                }
            }
        }

        /*
        000
        ?X0
        000
        */

        if (x >= 0 && x <SIZE_ROW && y-1 >= 0 && y-1<SIZE_COL)
        {
            if(x==goal.first && y-1 == goal.second){
                
                cellsWithHeurystics[x][y-1].x_of_parent = x;
                cellsWithHeurystics[x][y-1].y_of_parent = y;

                cout<<"Lady's and Gentelmen, we got him!"<<endl;

                gainedGoal = true;

                printPath(cellsWithHeurystics, goal);

                return;
            }else if(closedList[x][y-1] == false && grid[x][y-1] == true){
                gNew = cellsWithHeurystics[x][y-1].g + 1.0;
                hNew = calculateValueOfH(x, y - 1, goal);
                fNew = gNew + hNew;

                if(cellsWithHeurystics[x][y - 1].f == __FLT_MAX__ || cellsWithHeurystics[x][y - 1].f > fNew){
                
                    openList.insert(make_pair(fNew, make_pair(x, y - 1)));

                    cellsWithHeurystics[x][y - 1].f = fNew;
                    cellsWithHeurystics[x][y - 1].g = gNew;
                    cellsWithHeurystics[x][y - 1].h = hNew;
                    cellsWithHeurystics[x][y - 1].x_of_parent = x;
                    cellsWithHeurystics[x][y - 1].y_of_parent = y;

                }
            }
        }


        /*
        000
        0X?
        000
        */

        if (x >= 0 && x <SIZE_ROW && y+1 >= 0 && y+1<SIZE_COL)
        {
            if((x)==goal.first && (y+1) == goal.second){
                
                cellsWithHeurystics[x][y+1].x_of_parent = x;
                cellsWithHeurystics[x][y+1].y_of_parent = y;

                cout<<"Lady's and Gentelmen, we got him!"<<endl;

                gainedGoal = true;

                printPath(cellsWithHeurystics, goal);

                return;
            }else if(closedList[x][y+1] == false && grid[x][y+1] == true){
                gNew = cellsWithHeurystics[x][y+1].g + 1.0;
                hNew = calculateValueOfH(x, y+1, goal);
                fNew = gNew + hNew;

                if(cellsWithHeurystics[x][y+1].f == __FLT_MAX__ || cellsWithHeurystics[x][y+1].f > fNew){
                
                    openList.insert(make_pair(fNew, make_pair(x, y+1)));

                    cellsWithHeurystics[x][y+1].f = fNew;
                    cellsWithHeurystics[x][y+1].g = gNew;
                    cellsWithHeurystics[x][y+1].h = hNew;
                    cellsWithHeurystics[x][y+1].x_of_parent = x;
                    cellsWithHeurystics[x][y+1].y_of_parent = y;

                }
            }
        }
        /*
        ?00
        0X0
        000
        */

        if (x-1 >= 0 && x-1 <SIZE_ROW && y-1 >= 0 && y-1<SIZE_COL)
        {
            if((x-1)==goal.first && (y-1) == goal.second){
                
                cellsWithHeurystics[x-1][y-1].x_of_parent = x;
                cellsWithHeurystics[x-1][y-1].y_of_parent = y;

                cout<<"Lady's and Gentelmen, we got him!"<<endl;

                gainedGoal = true;

                printPath(cellsWithHeurystics, goal);

                return;
            }else if(closedList[x-1][y-1] == false && grid[x-1][y-1] == true){
                gNew = cellsWithHeurystics[x-1][y-1].g + 1.0;
                hNew = calculateValueOfH(x-1, y-1, goal);
                fNew = gNew + hNew;

                if(cellsWithHeurystics[x-1][y-1].f == __FLT_MAX__ || cellsWithHeurystics[x-1][y-1].f > fNew){
                
                    openList.insert(make_pair(fNew, make_pair(x-1, y-1)));

                    cellsWithHeurystics[x-1][y-1].f = fNew;
                    cellsWithHeurystics[x-1][y-1].g = gNew;
                    cellsWithHeurystics[x-1][y-1].h = hNew;
                    cellsWithHeurystics[x-1][y-1].x_of_parent = x;
                    cellsWithHeurystics[x-1][y-1].y_of_parent = y;

                }
            }
        }
        /*
        00?
        0X0
        000
        */

        if (x-1 >= 0 && x-1 <SIZE_ROW && y+1 >= 0 && y+1<SIZE_COL)
        {
            if((x-1)==goal.first && (y+1) == goal.second){
                
                cellsWithHeurystics[x-1][y+1].x_of_parent = x;
                cellsWithHeurystics[x-1][y+1].y_of_parent = y;

                cout<<"Lady's and Gentelmen, we got him!"<<endl;

                gainedGoal = true;

                printPath(cellsWithHeurystics, goal);

                return;
            }else if(closedList[x-1][y+1] == false && grid[x-1][y+1] == true){
                gNew = cellsWithHeurystics[x-1][y+1].g + 1.0;
                hNew = calculateValueOfH(x-1, y+1, goal);
                fNew = gNew + hNew;

                if(cellsWithHeurystics[x-1][y+1].f == __FLT_MAX__ || cellsWithHeurystics[x-1][y+1].f > fNew){
                
                    openList.insert(make_pair(fNew, make_pair(x-1, y+1)));

                    cellsWithHeurystics[x-1][y+1].f = fNew;
                    cellsWithHeurystics[x-1][y+1].g = gNew;
                    cellsWithHeurystics[x-1][y+1].h = hNew;
                    cellsWithHeurystics[x-1][y+1].x_of_parent = x;
                    cellsWithHeurystics[x-1][y+1].y_of_parent = y;

                }
            }
        }
        /*
        000
        0X0
        ?00
        */

        if (x+1 >= 0 && x+1 <SIZE_ROW && y-1 >= 0 && y-1<SIZE_COL)
        {
            if((x+1)==goal.first && (y-1) == goal.second){
                
                cellsWithHeurystics[x+1][y-1].x_of_parent = x;
                cellsWithHeurystics[x+1][y-1].y_of_parent = y;

                cout<<"Lady's and Gentelmen, we got him!"<<endl;

                gainedGoal = true;

                printPath(cellsWithHeurystics, goal);

                return;
            }else if(closedList[x+1][y-1] == false && grid[x+1][y-1] == true){
                gNew = cellsWithHeurystics[x+1][y-1].g + 1.0;
                hNew = calculateValueOfH(x+1, y-1, goal);
                fNew = gNew + hNew;

                if(cellsWithHeurystics[x+1][y-1].f == __FLT_MAX__ || cellsWithHeurystics[x+1][y-1].f > fNew){
                
                    openList.insert(make_pair(fNew, make_pair(x+1, y-1)));

                    cellsWithHeurystics[x+1][y-1].f = fNew;
                    cellsWithHeurystics[x+1][y-1].g = gNew;
                    cellsWithHeurystics[x+1][y-1].h = hNew;
                    cellsWithHeurystics[x+1][y-1].x_of_parent = x;
                    cellsWithHeurystics[x+1][y-1].y_of_parent = y;

                }
            }
        }
        /*
        000
        0X0
        00?
        */

        if (x-1 >= 0 && x-1 <SIZE_ROW && y+1 >= 0 && y+1<SIZE_COL)
        {
            if((x-1)==goal.first && (y+1) == goal.second){
                
                cellsWithHeurystics[x-1][y+1].x_of_parent = x;
                cellsWithHeurystics[x-1][y+1].y_of_parent = y;

                cout<<"Lady's and Gentelmen, we got him!"<<endl;

                gainedGoal = true;

                printPath(cellsWithHeurystics, goal);

                return;
            }else if(closedList[x-1][y+1] == false && grid[x-1][y+1] == true){
                gNew = cellsWithHeurystics[x-1][y+1].g + 1.0;
                hNew = calculateValueOfH(x-1, y+1, goal);
                fNew = gNew + hNew;

                if(cellsWithHeurystics[x-1][y+1].f == __FLT_MAX__ || cellsWithHeurystics[x-1][y+1].f > fNew){
                
                    openList.insert(make_pair(fNew, make_pair(x-1, y+1)));

                    cellsWithHeurystics[x-1][y+1].f = fNew;
                    cellsWithHeurystics[x-1][y+1].g = gNew;
                    cellsWithHeurystics[x-1][y+1].h = hNew;
                    cellsWithHeurystics[x-1][y+1].x_of_parent = x;
                    cellsWithHeurystics[x-1][y+1].y_of_parent = y;

                }
            }
        }
    }

    if(gainedGoal == false){
        cout<<"There is no goal!"<<endl;
    }

    return;
    
}

int main(){


    
    return 0;
}