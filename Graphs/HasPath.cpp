#include <iostream>
using namespace std;


bool isPath(int **edges, int n, int start, int end, bool* visited){
    if(start == end){
        return true;
    }
    
    visited[start] = true;
    
    for(int i  = 0; i<n; i++){
        if(i==start){
            continue;
        }
        if(edges[start][i] == 1 && !visited[i]){
            bool ans = isPath(edges, n, i, end, visited);
            if(ans){
                return true;
            }
        }
    }
    
    return false;
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
        visited[i] = false;
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    
    
    bool check = isPath(edges, V, v1, v2, visited);
    if(check){
        return true;
    } else {
        return false;
    }

}

