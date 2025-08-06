#include <iostream>
#include <vector>

using namespace std;

void search(vector<vector<int>> &adjusments, vector<bool> &visited, int start, vector<int> &result){

    visited[start] = true;

    result.push_back(start);

    for (int i : adjusments[start])
    {
        if(visited[i] == false){
            search(adjusments, visited, i, result);
        }
    }
    
}

vector<int> DFS(vector<vector<int>> &adjustments){
    
    vector<int> result;

    vector<bool> visited(adjustments.size(), false);

    search(adjustments, visited, 0, result);

    return result;
}

int main(){

    int count_of_nodes = 6;

    vector<vector<int>> adjustments(count_of_nodes);

    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{2,3},{3,4},{4,5}};

    for (auto &edge : edges){
        adjustments[edge[0]].push_back(edge[1]);
        adjustments[edge[1]].push_back(edge[0]);
    }

    vector<int> result = DFS(adjustments);

    for(int i = 0; i < count_of_nodes; i++){
        cout<<result[i]<<" ";
    }
}