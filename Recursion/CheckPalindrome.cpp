
#include <iostream>
using namespace std;
#include<string.h>
bool checkPalindrome(char input[], int size){
    if(size <= 0){
        return true;
    }
    
    if(input[0] != input[size-1]){
        return false;
    }
    
    return checkPalindrome(input+1, size-2);
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int size = strlen(input);
    return checkPalindrome(input, size);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

