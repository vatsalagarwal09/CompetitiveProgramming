#include <iostream>
using namespace std;
#include<string.h>
#include <cstdlib>
#include<stack>
int countBracketReversals(char input[]){
	// Write your code here
  //  stack<char> s;
    int n = strlen(input);
    if(n%2 != 0){
        return -1;
    }
    stack<char> s;
    
    for(int i = 0; i<n; i++){
        if(input[i] == '{'){
            s.push(input[i]);
            continue;
        }
        
        if(input[i] == '}'){
            if(s.empty() ==true){
                s.push(input[i]);
            } else if(s.empty() ==false && s.top() == '{'){
                s.pop();
            } else if(s.empty() == false && s.top() != '{'){
                s.push(input[i]);
            }
        }
    }
    
    int count = 0;
    
    while(s.empty() != true){
        char c1 = s.top();
        s.pop();
        
        char c2 = s.top();
        s.pop();
        
        if(c1 == c2){
            count++;
        } else {
            count += 2;
        }
    }
    
    return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}
