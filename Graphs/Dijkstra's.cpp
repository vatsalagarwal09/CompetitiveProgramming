#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int *distance, bool *visited, int n){
    int minVertex = -1;
    for(int i = 0; i<n; i++){
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
    
    return minVertex;
}

void djikstra(int **edges, int n){
    bool *visited = new bool[n];
    int *distance = new int[n];
    
    for(int i = 0; i<n; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    
    distance[0] = 0;
    
    for(int i = 0; i<n-1; i++){
        int minVertex = findMinVertex(distance, visited, n);
        visited[minVertex] = true;
        for(int j = 0; j<n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                int dist = distance[minVertex] + edges[minVertex][j];
                if(dist < distance[j]){
                    distance[j] = dist;
                }
            }
        }
    }
    
    
    for(int i = 0; i<n; i++){
        cout << i << " " << distance[i] << endl;
    }
}

int main()
{
  int V, E, tempX, tempY;
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
    
    djikstra(edges, V);
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}

