#include <iostream>
using namespace std;

void print(int **edges, int n, int startingVertex, bool *visited){
    cout << startingVertex << "\n";
    visited[startingVertex] = true;     //jese hi kisi vertex ko print kiya, use mark krdenge visited

    for(int i=0; i<n; i++){
        if(edges[startingVertex][i]){
            //agar vertex already visited hai, to use firse na 
            //print kro and continue kro with next iteration.
            if(visited[i]){
                continue;
            }
            print(edges, n, i, visited);        //Recursive call to print all the other vertices.
        }
    }
}
//---------------------------------------------------------------------------------------------------------------
int main(){
    cout<<"Enter no. of vertices and no. of edges: ";
    int n;  //no. of vertices
    int e;  //no. of edges
    cin >> n >> e;

    //Adjacency Matrix
    int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] =  new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    //Taking input all the edges from user
    cout<<"/n Enter edges: ";
    for(int i=0; i<e; i++){
        int first;
        int second;
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    //array to mark which all vertices have already been
    //visited while printing vertices of graph.
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    //function to print all the vertices
    print(edges, n, 0, visited);
}