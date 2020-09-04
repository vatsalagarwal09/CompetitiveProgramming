#include <iostream>
#include<string.h>
#include<algorithm>

using namespace std;

void findLargestUniqueSubstring(char input[], char output[]){
	// Write your code here
    int n = strlen(input);
    int count = 0, final_count = 0, start = 0;;
    if(n==1){
        final_count = 1;
    }
    int final_start  = 0;
    for(int i = 0; i<n; i++){
        for(int j =  start; j<i; j++){
            if(input[i] == input[j]){
                start = j + 1;
            }
            count = i - start + 1;
        }
        
        if(final_count < count){
            final_start = start;
            final_count = count;
        }
    }
    
    int k = 0;
    for(int i = final_start; i<final_count+final_start;i++){
        output[k] = input[i];
        k++;
    }
    output[k] = '\0';
}


int main() {
    char input[1000], output[1000];
    cin.getline(input, 1000);
    findLargestUniqueSubstring(input, output);
    cout << output << endl;
}

