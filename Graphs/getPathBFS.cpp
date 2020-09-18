#include <iostream>
#include <vector>
using namespace std;

vector<int>* getPath(int **edges, int V, bool *visited, int tempX, int tempY){
    if(tempX == tempY){
        vector<int>* ans = new vector<int>();
        ans->push_back(tempX);
        return ans;
    }
    
    if(edges[tempX][tempY] == 1){
        vector<int>* ans = new vector<int>();
        ans->push_back(tempY);
        return ans;
    }
    
    visited[tempX] = true;
    
    for(int i = 0; i<V; i++){
        if(edges[tempX][i] == 1 && !visited[i]){
            
            vector<int>* smallAns = getPath(edges, V, visited, i, tempY);
            if(smallAns->size() != 0){
                smallAns->push_back(i);
                return smallAns;
            }
        }
    }
    
    vector<int> *smallAns = new vector<int> ();
    return smallAns;
}

int main()
{
  int V, E, tempX, tempY;
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
    
    cin >> tempX >> tempY;
    
    vector<int>* ans = getPath(edges, V, visited, tempX, tempY);
    
    for(int i = 0; i<ans->size(); i++){
        cout << ans->at(i) << " ";
    }

  return 0;
}

