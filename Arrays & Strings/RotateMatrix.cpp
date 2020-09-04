#include<iostream>
using namespace std;

void rotate(int **input, int n){
    
    for(int i = 0; i<n/2; i++){
        for(int j = i; j<n-i-1; j++){
            int temp =  input[i][j];
            input[i][j] = input[j][n-i-1];
            input[j][n-i-1] = input[n-1-i][n-1-j];
            input[n-1-i][n-1-j] = input[n-1-j][i];
            input[n-1-j][i] = temp;            
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    int **input = new int*[n];
    
    for(int i = 0; i < n; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    rotate(input, n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

