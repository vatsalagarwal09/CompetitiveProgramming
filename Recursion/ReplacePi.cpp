#include <iostream>
using namespace std;
#include<string.h>
void replacePi(char input[]) {
	// Write your code here
    if(input[1] == '\0'){
        return;
    }
    
    if(input[0] == 'p' && input[1] == 'i'){
        int n = strlen(input);
        int i = 0;
        for(i = n-1; i>=2; i--){
            input[i+2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        input[n+2] = '\0';      
        
        replacePi(input+4);
    }
    
    replacePi(input+1);   
    
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

