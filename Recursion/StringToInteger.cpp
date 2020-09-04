#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int stringToNumber(char input[]) {
    // Write your code here
    if(input[1] == '\0'){
        return (input[0] - 48);
    }
    
    int smallAns = stringToNumber(input + 1);
    
    int i = strlen(input) - 1;
    
    int ans = pow(10, i) * (input[0]-48);
    return (ans + smallAns);
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}

