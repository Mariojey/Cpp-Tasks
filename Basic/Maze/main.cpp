#include <iostream>

using namespace std;

#define ARRAY_WIDTH 10
#define ARRAY_HEIGHT 10

enum Type{
    R,
    I,
    N,
    UNDEFINED
};

int ** pathfinding (int **maze, int ** path, int localizationX, int localizationY, int ** visited)
{
    if(localizationY == ARRAY_HEIGHT - 1 && localizationX == ARRAY_WIDTH - 1){
        return path;
    }else if(localizationX + 1 < ARRAY_WIDTH && localizationY < ARRAY_HEIGHT)
    {
        if(maze[localizationY][localizationX + 1] == 1 && visited[localizationY][localizationX + 1] == 0){
            path[localizationY][localizationX + 1] = 2;
            visited[localizationY][localizationX + 1] = 1;
            pathfinding(maze, path, localizationX + 1, localizationY, visited);
        }else if(maze[localizationY + 1][localizationX] == 1 && visited[localizationY][localizationX + 1] == 0){
            path[localizationY + 1][localizationX] = 2;
            visited[localizationY + 1][localizationX] = 1;
            pathfinding(maze, path, localizationX, localizationY + 1, visited);
        }else{
            path[localizationY][localizationX] = maze[localizationY][localizationX];
            if(localizationX - 1 >= 0){
                if(path[localizationX - 1][localizationY] == 2)
                {
                    pathfinding(maze, path, localizationX - 1, localizationY, visited);
                }
                //TODO
            }
        }
    }
}


int main()
{
    
    string firstUserInput;
    enum Type givenFindingMethod;
    
    cin>>firstUserInput;
    
    if(firstUserInput == "R"){
        givenFindingMethod = R;
    }else if(firstUserInput == "I"){
        givenFindingMethod = I;
    }
    else if(firstUserInput == "N"){
        givenFindingMethod = N;
    }else{
        givenFindingMethod = UNDEFINED;
    }
    
    int ** maze = new int * [ARRAY_HEIGHT];
    for (int row = 0; row < ARRAY_HEIGHT; ++row){
        
        maze[row] = new int[ARRAY_WIDTH];
        
    }
    
    int ** path = new int * [ARRAY_HEIGHT];
    for (int row = 0; row < ARRAY_HEIGHT; ++row){
        path[row] = new int[ARRAY_WIDTH];
    }

    int ** visited = new int * [ARRAY_HEIGHT];
    for(int row = 0; row < ARRAY_HEIGHT; ++row){
        visited[row] = new int[ARRAY_WIDTH];
    }

    visited[0][0] = 1;
    
    for(int row = 0; row < ARRAY_HEIGHT; row++){
        for(int col = 0; col < ARRAY_WIDTH; col++){
            cin>>maze[row][col];
        }
    }
    return 0;
}