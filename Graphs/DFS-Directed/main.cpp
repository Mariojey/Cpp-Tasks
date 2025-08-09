#include <iostream>
#include <vector>

using namespace std;

void search(vector<vector<int>> &adjustments, vector<bool> &visited, int start){

    visited[start] = true;

    cout << start << " ";

    for (int i : adjustments[start])
    {
        if(visited[i] == false){
            search(adjustments, visited, i);
        }
    }
    
}

void DFS(vector<vector<int>> &adjustments, int start){
    
    vector<bool> visited(adjustments.size(), false);

    search(adjustments, visited, start);
}

int main(){

    int count_of_nodes = 10;

    vector<vector<int>> adjustments(count_of_nodes);

    vector<vector<int>> edges = {{0,1},{0,3},{1,2},{2,4},{3,4},{3,5},{4,6},{6,9},{4,7},{7,8},{5,8},{8,9}};

    for (auto &edge : edges)
    {
        adjustments[edge[0]].push_back(edge[1]);
    }

    int start = 0;
    cout << start << endl;
    DFS(adjustments, start);

    return 0;
    
}