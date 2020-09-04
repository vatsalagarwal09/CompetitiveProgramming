#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;
void reverseEachWord(char input[]) {
    // Write your code here
    int n = strlen(input);
    int j = 0;
    for(int i = 0; i<n; i++){
        j = i;
        int start_count = j;
        int final_count = j;
        while(input[i] != ' ' && input[i] != '\0'){
            final_count++;
            i++;
        }
        
        std::reverse(input + start_count, input + final_count);
    }
}

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseEachWord(input);
    cout << input << endl;
}

