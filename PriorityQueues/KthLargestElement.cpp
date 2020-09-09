#include <iostream>
#include <vector>
using namespace std;
#include<queue>

int kthLargest (vector<int> arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<k; i++){
        pq.push(arr[i]);
    }
    
    int m = arr.size();
    for(int i = k; i<m; i++){
        if(pq.top() < arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    
    return pq.top();
}

int main(){
    int n, k, s;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        arr.push_back(s);
    }
    cin >> k;
    cout << kthLargest(arr, n, k) << endl;
}

