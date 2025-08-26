#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>>& adjustments){
    
    int size = adjustments.size();

    int root = 0;

    vector<int> result;
    queue<int> toVisit;
    vector<bool> visited(size, false);

    visited[root] = true;
    toVisit.push(root);

    while (!toVisit.empty())
    {
        int current = toVisit.front();
        toVisit.pop();
        result.push_back(current);

        for (int item : adjustments[current])
        {
            if (!visited[item])
            {
                visited[item] = true;
                toVisit.push(item);
            }
            
        }
        
    }

    return result;
    
}

int main(){

    vector<vector<int>> adjustments = {{1,2},{0,2,3},{0,4},{1,4},{2,3}};

    vector<int> answer = bfs(adjustments);

    for(auto item: answer){
        cout<<item<<" ";
    }

    return 0;
}