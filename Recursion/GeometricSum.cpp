#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
#include<algorithm>
double geometricSum(int k) {
    // Write your code here
    if(k==0){
        return 1;
    }
    
    double small_ans = geometricSum(k-1);
    return small_ans + pow(2, -k);
}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}

