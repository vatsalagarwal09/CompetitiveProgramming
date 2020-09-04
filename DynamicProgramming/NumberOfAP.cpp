#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#include<algorithm>
#define MAX 1000001 

int mod=100001;
using namespace std;
int numofAP(int *a, int n){
    int ans = n + 1;
    unordered_map<int, int> *map = new unordered_map<int, int>[n];
    for(int i = 0; i<n-1; i++){
        for(int j = i + 1; j < n; j++){
            int diff = a[j] - a[i];
            map[i][diff] += 1;
            ans = (ans + 1) % 100001;
        }
    }
    
    for(int i  = n-3; i>=0; i--){
        for(int j =  i+1; j<n; j++){
            int diff = a[j] - a[i];
            map[i][diff] = (map[i][diff] + map[j][diff]) % 100001;
            ans = (ans + map[j][diff]) % 100001;
        }
    }
    
    delete []map;
    return ans;
}

int main(){

    int N;
    cin >> N;

    int *arr = new int[N+1];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << numofAP(arr, N) << endl;

    return 0;
}

