#include <iostream>
#include <cmath>
using namespace std;
#include<bits/stdc++.h>
int binaryCountHelper(int h, int *arr){
	if(h == 0 || h==1){
		return 1;
	}
	
	if(arr[h] != -1){
		return arr[h];
	}
	
	arr[h] = binaryCountHelper(h-1, arr) * binaryCountHelper(h-1, arr) + 2 * binaryCountHelper(h-1, arr) * binaryCountHelper(h-2, arr);
	
	return arr[h];    
}


int binaryTreesOfHeightH(int h) {
    int *output = new int[h+1];
    for(int i = 0; i<=h; i++){
        output[i] = -1;
    }
    
    return binaryCountHelper(h, output);
}

int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
}

