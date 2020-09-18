#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int *weight, bool *visited, int V){
    int minVertex = -1;
    for(int i = 0; i<V; i++){
        if(!visited[i] && (minVertex == -1 || weight[minVertex] > weight[i])){
          //  weight[i] = weight[minVertex];
            minVertex = i;
        }
    }
    
    return minVertex;
}

void prims(int **edges, int V){
    int *parent = new int[V];
    int *weight = new int[V];
    bool *visited = new bool[V];
    
    for(int i = 0; i<V; i++){
    //    parent[i]  = i;
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    
    parent[0] = -1;
    weight[0] = 0;
    
    for(int i = 0; i<V-1; i++){
        int minVertex = findMinVertex(weight, visited, V);
        visited[minVertex] = true;
        for(int j = 0; j<V; j++){
            if(!visited[j] && edges[minVertex][j] != 0){
                if(edges[minVertex][j] < weight[j]){
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    
    for(int i = 1; i<V; i++){
        if(parent[i] < i){
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        } else {
            cout << i <<  " " << parent[i] << " " << weight[i] << endl;  
        }
    }
}


int main()
{
    int V, E;
    cin >> V >> E;
    
    int **edges = new int*[V];
    for(int i =0; i<V; i++){
        edges[i] = new int[V];
        for(int j = 0; j<V; j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i = 0; i<E; i++){
        int a, b, weight;
        cin >> a >> b >> weight;
        edges[a][b] = weight;
        edges[b][a] = weight;
    }
    
    prims(edges, V);
  return 0;
}

