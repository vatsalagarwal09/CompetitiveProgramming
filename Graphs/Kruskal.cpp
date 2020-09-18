#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class edge{
  public:
    int start;
    int end;
    int weight;
};

bool compare(edge e1, edge e2){
    return e1.weight < e2.weight;
}

int findParent(int v, int* parent){
    if(v==parent[v]){
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskal(edge *input, int V, int E){
    sort(input, input+E, compare);
    edge *output = new edge[E-1];
    int *parent = new int[E];
    for(int i = 0; i<E; i++){
        parent[i] = i;
    }
    
    int count = 0;
    int i = 0;
    while(count != E-1){
        edge current = input[i];
        int startParent = findParent(current.start, parent);
        int endParent = findParent(current.start, parent);
        
        if(startParent != endParent){
            output[count] = current;
            count++;
            parent[startParent] = endParent;
        }
        i++;
    }
    
    for(int i = 0; i<E-1; i++){
        int x = min(output[i].start, output[i].end);
        int y = max(output[i].start, output[i].end);
        cout << x << " " << output[i].weight << " " << y << end;
    }  
}

int main()
{
    int V, E;
    cin >> V >> E;
    
    edge *input = new edge[E];
    for(int i = 0; i<E; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        input[i].start = start;
        input[i].end = end;
        input[i].weight = weight;
    }
    
    
    kruskal(input, V, E);
    return 0;
}

