#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    int i = 0;
    for(i = 1; i<=(n+1)/2; i++){
        for(int k=1; k<=i-1; k++){
            cout << " ";
        }
        for(int j=1; j<=i; j++){
            cout << "* " ; 
        }
        cout << endl;
    }   
    
    for(i; i<=n; i++){
        for(int k=n-i; k>=1; k--){
            cout << " " ;
        }
        
        for(int j=n-i+1; j>=1; j--){
            cout << "* " ;
        }
        cout << endl;
    }
        
}


