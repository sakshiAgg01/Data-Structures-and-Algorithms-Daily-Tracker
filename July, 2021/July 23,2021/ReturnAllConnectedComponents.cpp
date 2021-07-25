#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//------------------------------------------------------------------------------------------------------------
vector<int> getComponent(int **edges, int n, int startVertex, bool *visited)
{
    vector<int> comp;
    queue<int> pendingVertices;
    pendingVertices.push(startVertex);
    comp.push_back(startVertex);
    visited[startVertex] = true;

    while (!pendingVertices.empty())
    {
        int currVertex = pendingVertices.front();
        pendingVertices.pop();

        for (int i = 0; i < n; i++)
        {
            if (edges[currVertex][i] && !visited[i])
            {
                pendingVertices.push(i);
                comp.push_back(i);
                visited[i] = true;
            }
        }
    }
    return comp;
}
//---------------------------------------------------------------------------------------------------
vector<vector<int>> returnComponents(int **edges, int n, bool *visited){
    vector<vector<int>> comps;
    vector<int> comp;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            comp = getComponent(edges, n, i, visited);
        }
        comps.push_back(comp);
    }
    return comps;
}

//------------------------------------------------------------------------------------------------------------
int main(){
    int n;
    int e;
    cin >> n >> e;

    int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++){
        int first;
        int second;
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    vector<vector<int>> comps = returnComponents(edges, n, visited);
    for(int i=0; i<comps.size(); i++){
        for (int j=0; j < comps[i].size(); j++){
            cout << comps[i][j] << " ";
        }
        cout << endl;
    }
}