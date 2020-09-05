#include <iostream>
using namespace std;

#include<stack>
int* stockSpan(int *price, int size) {
	// Write your code here
    int *output = new int[size];
    stack<int> s;
    
    for(int i = 0; i<size; i++){
        if(s.empty() == true){
            s.push(i);
            output[i] = i+1;
            continue;
        }
        
        if(price[i] <= price[s.top()]){
            output[i] = i - s.top();
            s.push(i);
            continue;
        }
        
        if(price[i] >  price[s.top()]){
            while( s.empty() == false && price[i] > price[s.top()]){
                s.pop();
            }
            
            if(s.empty() == true){
                output[i] = i + 1;
            } else {
                output[i] = i - s.top();
            }
            
            s.push(i);
        }
    }
    
    return output;

}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}

