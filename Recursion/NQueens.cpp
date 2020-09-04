#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
void placeNQueens(int n, int i, int *output){
    int b = pow(n,2);
    
    if(i == n){
        for(int a = 0; a<b; a++){
            cout << output[a] << " ";
        }
        cout << endl;
        return;
    }
    
    int j = 0, k = 0;
    
    for(k = 0; k<n; k++){
        bool check = true;
        
        
        for(j = 0; j<n; j++){
            if(output[j*n + k] == 1){
                check = false;
                break;
            }
        }
        
        if(check == false){
            continue;
        }
        
        int a = i;
        int b = k;
        while(a>0 && b>0){
            if(output[(a-1) * n + (b-1)] == 1){
                check = false;
                break;
            }
            a--;
            b--;
        }
        
        if(check == false){
            continue;
        }
        
        
        a = i;
        b = k+1;
        
        while(a>0 && b<=n-1){
            if(output[(a-1) * n + b] == 1){
                check = false;
                break;
            }
            a--;
            b++;
        }
        
        if(check == false){
            continue;
        }        
        
        a = i+1;
        b = k;
        
        while(a<=n-1 && b>0){
            if(output[a * n + (b-1)] == 1){
                check = false;
                break;
            }
            a++;
            b--;
        }
        
        if(check == false){
            continue;
        }        
        
        a = i+1;
        b = k+1;
        
        while(a<=n-1 && b<=n-1){
            if(output[a * n + b] == 1){
                check = false;
                break;
            }
            a++;
            b++;
        }
        
        if(check == false){
            continue;
        }
        
        
        output[i*n + k] = 1;
        placeNQueens(n, i+1, output);
        output[i*n + k] = 0;
    }
    return;
}

void placeNQueens(int n){
    int a = pow(n,2);
    int *output = new int[a];
    for(int i = 0; i<a; i++){
        output[i] = 0;
    }
    placeNQueens(n, 0, output);
}

int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}




