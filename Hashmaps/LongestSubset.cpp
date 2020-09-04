#include <cmath>
#include <iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int max(int arr[], int n) {
    for(int i = 0; i<n ;i++){
        if(arr[i] == 0){
            arr[i] = -1;
        }
    }
    
    int maxsize = -1;
    int maxsize_start = -1;
    int sumleft[n];
    for(int i = 0; i<n; i++){
        sumleft[i] = -1;
    }
    sumleft[0] = arr[0];

    for(int i = 1; i<n; i++){
        sumleft[i] = arr[i] + sumleft[i-1];
    }
    
    for(int i = n-1; i>=0; i--){
        if(sumleft[i] == 0){
            maxsize_start = i + 1;
            break;
        }
    }
    
    unordered_map<int, int> m;
    
    for(int i = 0; i<n; i++){
        if(m.count(sumleft[i]) == 0){
            m[sumleft[i]] = i;
        } else {
            int diff = i - m[sumleft[i]];
            maxsize = max(diff, maxsize);
        }
    }
    
    maxsize = max(maxsize, maxsize_start);
    
    if(maxsize == -1){
        return 0;
    } else {
        return maxsize;
    }    
 }

int main() {
    	int n=0;
    	cin>>n;
    	int *arr = new int[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}
    	
    	cout << max(arr,n);
    	
	
}

