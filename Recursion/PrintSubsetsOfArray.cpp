#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[], int size, int output[], int m){
    if(size == 0){
        for(int i = 0; i<m; i++){
            cout << output[i] << " ";  
        }
        cout << endl;
        return;
    }
    
    int smallOutput[100];
    int i = 0;
    
    for(i = 0; i<m; i++){
        smallOutput[i] = output[i];
    }
    smallOutput[i] = input[0];
    

    printSubsetsOfArray(input + 1, size - 1, smallOutput, m + 1);
    printSubsetsOfArray(input + 1, size - 1, output, m);
    return;   
}


void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    
    int output[size];
    printSubsetsOfArray(input, size, output, 0);
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}

