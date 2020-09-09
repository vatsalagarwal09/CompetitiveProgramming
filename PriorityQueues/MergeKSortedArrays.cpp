#include <iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>*> input){

    int n = input.size();
    vector<int>* output;
    priority_queue<int, vector<int>, greater<int>> pq;

    
    for(int i = 0; i<n; i++){
        output = input[i];
        while(output->size() != 0){
            pq.push(output->back());
            output->pop_back();
        }
    }
    
    vector<int> finalOutput;
    while(pq.size() != 0){
        finalOutput.push_back(pq.top());
        pq.pop();
    }
    
    return finalOutput;
}

int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}

