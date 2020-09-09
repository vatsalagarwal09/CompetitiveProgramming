#include <iostream>
using namespace std;

bool checkMaxHeap(int arr[], int n, int pi, int child1, int child2){
    if(child2 > n-1){
        if(child1 > n-1){
            return true;
        } else  {
             if(arr[pi] >= arr[child1]){
                 return true;
             } else {
                 return false;
             }
        }
    }
    
    return (arr[pi] >= arr[child1]) && (arr[pi] >= arr[child2]) && checkMaxHeap(arr, n, child1, 2 * child1 + 1, 2 * child1 + 2) && checkMaxHeap(arr, n, child2, 2 * child2 + 1, 2 * child2 + 2);
    
    
}

bool checkMaxHeap(int arr[], int n){
    int parentIndex = 0;
    int child1 = 2 * parentIndex + 1;
    int child2 = 2 * parentIndex + 2;
    
    return checkMaxHeap(arr, n, parentIndex, child1, child2);

}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}


