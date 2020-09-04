#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = n-1; j>=i; j--){
            cout << " ";
        }
        int m = i;
        for(int k = 1; k<=i; k++){
            cout << m;
            m++;
        }
        m--;
        for(int l=1; l<i; l++){
            m--;
            cout << m;
        }
        cout << endl;
    }
}

