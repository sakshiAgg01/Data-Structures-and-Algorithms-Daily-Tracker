#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
//---------------------------------------------------------------------------------------------------------
vector<int>* getPath(int **edges, int n, int v1, int v2, bool *visited){
    queue<int> pendingVertices;
    pendingVertices.push(v1);
    visited[v1] = true;

    unordered_map<int,int> parent;
    bool done = false;

    while(!pendingVertices.empty() && !done){
        int currVertex = pendingVertices.front();
        pendingVertices.pop();

        for(int i=0; i<n; i++){
            if(edges[currVertex][i] && !visited[i]){
                pendingVertices.push(i);
                parent[i] = currVertex;
                visited[i] = true;

                if(i == v2){
                    done = true;
                    break;
                }
            }
        }
    }

    if(!done){
        return NULL;
    }
    else{
        vector<int> *output = new vector<int>();
        int current = v2;
        output->push_back(v2);
        while(current != v1){
            current = parent[current];
            output->push_back(current);
        }
        return output;
    }
}
//---------------------------------------------------------------------------------------------------------
int main(){
    int n;  //no. of vertices
    int e;  //no. of edges
    cin>>n>>e;

    //Adjacency matrix
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
        cin>>first>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> *output = getPath(edges, n, v1, v2, visited);
    if(output != NULL){
        for (int i = 0; i < output->size(); i++)
        {
            cout << output->at(i) << " ";
        }
    }
}