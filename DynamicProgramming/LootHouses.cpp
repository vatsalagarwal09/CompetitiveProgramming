#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int getMaxMoneyHelper(int arr[], int n, int *output){
    if(n-1 == 0 || n-1==1){
        return arr[n-1];
    }
    
    if(output[n-1] != 0){
        return output[n-1];
    }
    
    output[n-1] = max(getMaxMoneyHelper(arr, n-1, output), max(getMaxMoneyHelper(arr, n-2, output) + arr[n-1], getMaxMoneyHelper(arr, n-3, output) + arr[n-1]));
    return output[n-1];
    
}

int getMaxMoney(int arr[], int n){

    int *output = new int[n];
    for(int i = 0; i<n; i++){
        output[i] = 0;
    }
    int temp = getMaxMoneyHelper(arr, n, output);
    int ans = output[0];
    for(int i = 0; i<n; i++){
        ans = max(ans, output[i]);
        
    }
    
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}


