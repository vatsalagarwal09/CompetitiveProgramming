#include <iostream>
using namespace std;
void merge(int input[], int l, int m, int r){
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = input[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = input[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            input[k] = L[i]; 
            i++; 
        } 
        else
        { 
            input[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        input[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        input[k] = R[j]; 
        j++; 
        k++; 
    }     
}

void mergeSort(int input[], int size){
	// Write your code here
    int l = 0;
    int r = size-1;
    int m = (l+r)/2;
    
    if(l==r){
        return;
    }
    
    mergeSort(input, m+1);
    mergeSort(input + m + 1, size-m-1);
    
    merge(input, l, m , r);
    
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
