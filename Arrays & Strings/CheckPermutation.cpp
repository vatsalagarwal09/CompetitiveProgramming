#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;
bool isPermutation(char input1[], char input2[]){
    int count[256];
    int size1 = strlen(input1);
    int size2 = strlen(input2);
    
    if(size1 != size2){
        return false;
    }
    
    for(int i = 0; i<size1; i++){
        count[int(input1[i])]++;
    }
    
    for(int i = 0; i<size2; i++){
        count[int(input2[i])]--;
    }
    
    for(int i = 0; i<256; i++){
        if(count[i] != 0){
            return false;
        }
    }
    
    return true;
}

int main() {
    char input1[1000], input2[1000];
    cin.getline(input1, 1000);
    cin.getline(input2, 1000);
    if(isPermutation(input1, input2) == 1) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}

