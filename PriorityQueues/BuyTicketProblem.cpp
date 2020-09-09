#include <iostream>
#include <vector>
using namespace std;
#include<queue>
int buyTicket (int *arr, int n, int k){
    queue<int> q;
    priority_queue<int> pq;
    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
        q.push(arr[i]);
    }
    
    int count = 0;
    while(!pq.empty()){
        if(q.front() == pq.top()){
            pq.pop();
            q.pop();
            if(k==0){
                return count + 1;
            } else {
                count++;
                k--;
            }
        } else {
            q.push(q.front());
            q.pop();
            if(k == 0){
                k = q.size() - 1;
            } else {
                k--;
            }
        }
	}
}

int main(){
    int n, k, s;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    cout << buyTicket(arr, n, k) << endl;
}


