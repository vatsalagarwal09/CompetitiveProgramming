#include <iostream>
using namespace std;
void printSubsetSumToK(int input[], int size, int k, int output[], int m){
    int sum = 0;
    for(int i = 0; i<m; i++){
        sum += output[i];
    }
    if(sum > k){
        return;
    }
    if(sum == k){
        for(int i = 0; i<m; i++){
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    
    if(size==0){
        return;
    }
    
    int smallOutput[100];
    int i = 0;
    
    for(i = 0; i<m; i++){
        smallOutput[i] = output[i];
    }
    smallOutput[i] = input[0];
    printSubsetSumToK(input + 1, size - 1, k, smallOutput, m+1);
    printSubsetSumToK(input + 1, size - 1, k, output, m);
    return;
    
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[size];
    printSubsetSumToK(input, size, k, output, 0);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}

