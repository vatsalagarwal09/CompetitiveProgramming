#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int countBSTHelper(int n, int *arr){
	if(n==0 || n==1){
		return 1;
	}
	
	if(arr[n]!=0){
		return arr[n];
	} 
    int sum = 0;
    long long int a = pow(10, 9) + 7;
	
	for(int i = 1; i<=n; i++){
		sum = (countBSTHelper(n-i, arr) + countBSTHelper(i-1, arr)) % a;
        arr[n] = (arr[n] + sum) %a;
	}
	arr[n] = sum;
	return arr[n];
}

int countBST(int n){
    int *output = new int[n+1];
    for(int i = 0; i<=n; i++){
        output[i] = 0;
    }
    
    return countBSTHelper(n, output);
}

int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}

