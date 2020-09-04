#include <iostream>
#include<string.h>
#include<algorithm>

using namespace std;

void reverseStringWordWise(char input[]){
    int n = strlen(input);
    int j = 0;
    for(int i = 0; i<n/2; i++){
        std::swap(input[i], input[n-i-1]);     
    }
    
    for(int i = 0; i<n; i++){
        j=i;
        while(input[i] != ' ' && i<n){
            i++;
        }
        
        std::reverse(input + j, input + i);
    }
}



int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}

