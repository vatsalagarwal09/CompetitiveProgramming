#include <cmath>
#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_map>
using namespace std;

int minDistance(int arr[], int n){
    unordered_map<int, int> m;
    int min_repeat = INT_MAX;
    int repeat = 0;
    
    for(int i = 0; i<n; i++){        
        if(m.count(arr[i]) != 0){
            if(m[arr[i]] == m[arr[0]]){
                repeat = i - m[arr[i]] + 1;
            } else{
                repeat = i - m[arr[i]];
            }
            
            min_repeat = min(repeat, min_repeat);
            m[arr[i]] = i;
            continue;
        }

        if(i==0){
            m[arr[i]] = 1;
        } else {
            m[arr[i]] = i;
        }        
        
    }
    
    return min_repeat;
}

int main() {
    	int n=0;
    	cin>>n;
    	int *arr = new int[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	
    	cout << minDistance(arr,n);
    	
	
}

