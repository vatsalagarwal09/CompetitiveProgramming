#include <iostream>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h> 
using namespace std;


void lexicographicalOrder(int num, int i){

    if(i>num){
        return;
    }
    cout << i << endl;

        for(int j = 0; j <= 9; j++){
            lexicographicalOrder(num, 10 * i + j);
            if(10*i+j >num){
                break;            
            }
        }
    
    return;  
}

void lexicographicalOrder(int num){
	// Write your code here
    for(int i = 1; i<10; i++){
        lexicographicalOrder(num, i);
    }

}

int main() {
    int n;
    cin >> n;
    lexicographicalOrder(n);
}

