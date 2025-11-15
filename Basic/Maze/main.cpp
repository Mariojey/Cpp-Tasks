#include <iostream>
#include <stack>

using namespace std;

#define ARRAY_WIDTH 10
#define ARRAY_HEIGHT 10


bool znajdzRekurencyjnie(int maze[ARRAY_HEIGHT][ARRAY_WIDTH], int path[ARRAY_HEIGHT][ARRAY_WIDTH], int x, int y)
{
    if(x < 0 || x >= ARRAY_WIDTH || y < 0 || y >= ARRAY_HEIGHT || maze[y][x] == 0 || path[y][x] == 1)
    {
        return false;
    }

    path[y][x] = 1;

    if(x == ARRAY_WIDTH - 1 && y == ARRAY_HEIGHT - 1)
    {
        return true;
    }

    if(znajdzRekurencyjnie(maze, path, x+1, y)){
        return true;
    }
    if(znajdzRekurencyjnie(maze, path, x, y+1)){
        return true;
    }
    if(znajdzRekurencyjnie(maze, path, x-1, y)){
        return true;
    }
    if(znajdzRekurencyjnie(maze, path, x, y -1)){
        return true;
    }

    return false;
}


bool znajdzNawrotami(int maze[ARRAY_HEIGHT][ARRAY_WIDTH], int path[ARRAY_HEIGHT][ARRAY_WIDTH], int x, int y)
{
    if(x < 0 || x >= ARRAY_WIDTH || y < 0 || y >= ARRAY_HEIGHT || maze[y][x] == 0 || path[y][x] == 1)
    {
        return false;
    }

    path[y][x] = 1;

    if(x == ARRAY_WIDTH - 1 && y == ARRAY_HEIGHT - 1)
    {
        return true;
    }

    if(znajdzRekurencyjnie(maze, path, x+1, y)){
        return true;
    }
    if(znajdzRekurencyjnie(maze, path, x, y+1)){
        return true;
    }
    if(znajdzRekurencyjnie(maze, path, x-1, y)){
        return true;
    }
    if(znajdzRekurencyjnie(maze, path, x, y -1)){
        return true;
    }

    path[y][x] = 0;

    return false;
}

bool znadzIteracyjnie(int maze[ARRAY_WIDTH][ARRAY_HEIGHT], int path[ARRAY_HEIGHT][ARRAY_WIDTH])
{
    stack<pair<int, int>> st;

    st.push({0,0});

    path[0][0] = 1;

    while(!st.empty()) {


        auto [x, y] = st.top();

        if(x==ARRAY_WIDTH - 1 && y == ARRAY_HEIGHT - 1){
            return true;
        }

        bool moved = false;

        int potentianDirections[4][2] = {
            {1,0},{0,1},{-1,0},{0,-1}
        };

        for(auto &direction: potentianDirections){

            int new_x = x + direction[0];
            int new_y = y + direction[1];

            if(new_x >= 0 && new_x < ARRAY_WIDTH && new_y >= 0 && new_y < ARRAY_HEIGHT && maze[new_y][new_x] == 1 && path[new_y][new_x] == 0)
            {
                path[new_y][new_x] = 1;
                st.push({new_x, new_y});

                moved = true;

                break;
            }
        }

        if(!moved){
            st.pop();
        }
    }

    return false;
}

void showPath(int maze[ARRAY_HEIGHT][ARRAY_WIDTH], int path[ARRAY_HEIGHT][ARRAY_WIDTH]){
    
    for (int row = 0; row < ARRAY_HEIGHT; row++)
    {
        for (int col = 0; col < ARRAY_WIDTH; col++)
        {
            if (path[row][col] == 1)
            {
                cout << "* ";
            }else{
                cout << maze[row][col]<<" ";
            }
            
        }
        cout<<endl;
        
    }
    
}


int main()
{
    
    int maze[ARRAY_HEIGHT][ARRAY_WIDTH];
    int path[ARRAY_HEIGHT][ARRAY_WIDTH] = {0};

    char type;
    cin>>type;


    for(int row = 0; row < ARRAY_HEIGHT; row++){
        for (int  col = 0; col < ARRAY_WIDTH; col++)
        {
            cin>>maze[row][col];
        }
        
    }

    bool foundedPath = false;

    if (type == 'R')
    {
        foundedPath = znajdzRekurencyjnie(maze, path, 0, 0);
    }else if(type == 'I'){
        foundedPath = znadzIteracyjnie(maze, path);
    }else if(type == 'N'){
        foundedPath = znajdzNawrotami(maze, path, 0, 0);
    }

    if(!foundedPath)
    {
        return 0;
    }

    
    showPath(maze, path);

    return 0;
}