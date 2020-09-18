#include <iostream>
#include<queue>
using namespace std;


void printBFS(int **edges, int V, int sv, bool *visited){
	queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv] = true;
    
    while(pendingNodes.empty() != false){
        int index = pendingNodes.front();
        pendingNodes.pop();
        cout << index << " ";
        for(int i = 0; i<V; i++){
            if(i==index){
                continue;
            }
            if(edges[i][index] == 1 && !visited[i]){
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
}


int main() {
    int V, E;
    cin >> V >> E;
	int **edges = new int*[V];
	for(int i = 0; i<V; i++){
		edges[i] = new int[V];
		for(int j = 0; j<V; j++){
			edges[i][j] = 0;
		}
	}
	
	for(int i = 0; i<E; i++){
		int a, b;
		cin >> a >> b;
		edges[a][b] = 1;
		edges[b][a] = 1;
	}
	
	bool *visited = new bool[V];
	for(int i = 0; i<V; i++){
		visited[i] = 0;
	}
    
    printBFS(edges, V, 0, visited);    
  return 0;
}










