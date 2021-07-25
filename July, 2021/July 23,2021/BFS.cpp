#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges, int n, int startVertex, bool *visited){
    queue<int> pendingVertices;
    pendingVertices.push(startVertex);
    visited[startVertex] = true;

    while(!pendingVertices.empty()){
        int currVertex = pendingVertices.front();
        pendingVertices.pop();

        cout<< currVertex<<endl;

        for(int i=0; i<n; i++){
            if(visited[i]){
                continue;
            }
            if(edges[currVertex][i] ){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------------
void BFS(int **edges, int n, bool *visited){

    for(int i=0; i<n; i++){
        if(!visited[i]){
            printBFS(edges, n, i, visited);
        }
    }
}
//----------------------------------------------------------------------------------------------------------
    int main()
{
    int n;  //no. of vertices
    int e;  //no. of edges
    cin >> n >> e;

    //Taking Adjacency matrix of size n x n and initializing all its cells with value 0.
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

    // //printing in BFS fashion
    // printBFS(edges, n, 0, visited);
    BFS(edges, n, visited);
}