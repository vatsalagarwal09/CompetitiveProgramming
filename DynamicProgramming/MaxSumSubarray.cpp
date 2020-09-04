#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int findSum(int arr[],int n){

    int current_max = 0;
    int max_sum = 0;
    int ans = INT_MIN;
    for(int i = 0; i<n; i++){
        current_max += arr[i]; 
        if(current_max >= arr[i]){
            max_sum = current_max;
        } else {
            max_sum = arr[i];
            current_max = max_sum;
        }
        
        ans = max(max_sum, ans);
    }
    
    return ans;
}
 

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
	cout<<findSum(arr,n);

    return 0;
}

