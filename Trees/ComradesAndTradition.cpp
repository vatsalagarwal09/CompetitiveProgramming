#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int height(int input[], int i, int n){

    int count = 0;
    int j = i;
    while(input[j] != -1){
        count++;
        j = input[j];
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    for(int k = 0; k<t; k++){
        int n;
        cin >> n;
        int *input = new int[n];
        for(int i = 0; i<n; i++){
            cin >> input[i];
        }
        
        for(int i = 0; i<n; i++){
            input[i]--;
        }
        
        int ans = 0;
        int total = (n * (n-1))/2;
        for(int i = 0; i<n; i++){
            int smallAns = height(input, i, n);
            ans += smallAns;
        }
        cout << ans << " " << total - ans << endl;
    }
	return 0;
}



