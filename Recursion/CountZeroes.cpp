#include <iostream>
using namespace std;
int countZeros(int n) {
    // Write your code here
    if(n==0){
        return 0;
    }
    
    int small_count = countZeros(n/10);
    
    if(n%10 == 0){
        return small_count + 1;
    }
    
    return small_count;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}

