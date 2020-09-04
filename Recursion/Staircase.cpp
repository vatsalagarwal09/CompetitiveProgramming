#include <iostream>
using namespace std;
int staircase(int n){
    
    if(n==0){
        return 1;
    }
    
    if(n<0){
        return 0;
    }
    
    int smallAns1 = staircase(n-1);
    int smallAns2 = staircase(n-2);
    int smallAns3 = staircase(n-3);
    
    return smallAns1 + smallAns2 + smallAns3;
    
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}

