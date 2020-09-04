#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
    cin >> n;
    int j = 0;
    for(int i = 1; i<=n; i++){
        for(j = 1; j<=i; j++){
            cout << j;
        }
        for(int l = 1; l<=2*(n-i); l++){
            cout << " ";
        }
        for(int k=j-1; k>=1; k--){
            cout << k;
        }
        cout << endl;
    }
}

