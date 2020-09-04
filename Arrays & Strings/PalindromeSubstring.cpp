#include <iostream>
#include<string.h>
using namespace std;
int countPalindromeSubstrings(char s[]) {
	// Write your code here
	int n = strlen(s);
    int count = 0;
    int j = 0, k = 0, l = 0;
    bool check = false;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            check = true;
            if(s[j] == s[i]){
                k = j;
                l = i;
                while(k<l){
                    if(s[k] != s[l]){
                        check = false;
                        break;
                    }
                    k++;
                    l--;
                }
                if(check==true){
                    count = count + 1;
                }
            
            }            
        }

    }
    
    count = count + n;
    return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}

