#include <iostream>

#include <bits/stdc++.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    
    if(input[0] == '\0'){
        output[0] = "";
        return 1;
    }
    
    int first = input[0] - 48;
    char firstchar = first + 'a' - 1;
    char secondchar = '\0';
    string smallOutput1[100];
    string smallOutput2[100];
    
    int smallAns1 = getCodes(input.substr(1), smallOutput1);
    int smallAns2 = 0;
    if(input[1] != '\0'){
        int second = first * 10 + input[1] - 48;
        if(second >=10 && second <= 26){
            secondchar = second + 'a' - 1;
            smallAns2 = getCodes(input.substr(2), smallOutput2);
        }
    }
    
    
    int k = 0;
    for(int i = 0; i<smallAns1; i++){
        output[k] = firstchar + smallOutput1[i];
        k++;
    }
    
    for(int i = 0; i<smallAns2; i++){
        output[k] = secondchar + smallOutput2[i];
        k++;
    }
    
    return k;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

