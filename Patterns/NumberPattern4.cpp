#include <iostream>
using namespace std;

// n - number of rows given
void printPattern(int n){
	// Write your code here
    int count = 0;
    int i = 0;
    for(i = 1; i<=(n+1)/2; i++){
        int j = n*count + 1;
        
        for(int k = 1; k<n; k++){
            cout << j << "*";
            j++;
        }

        cout << j;
        cout << endl;
        count += 2;
    }
    
    if(n%2 != 0){
        count = n-1;
        for(i; i<=n; i++){
            int j = count * n - (n-1);
            for(int k = 1; k<n; k++){
                cout << j << "*";
                j++;
            }
        cout << j;
        cout << endl;
        count -= 2;
        }
    
    } else {
       count = n-1;
        for(i; i<=n; i++){
            int j = count * n + 1;
            for(int k = 1; k<n; k++){
                cout << j << "*";
                j++;
            }
            
        cout << j;
        cout << endl;
        count -= 2;
        }
    
    }

    
}

