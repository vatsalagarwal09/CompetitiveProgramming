#include<iostream>
using namespace std;
#include<string.h>
#include<stack>

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
  

void evaluatePostfix(char exp[]) {
    int n = strlen(exp);
    char *output = new char[n];
    stack<char> s;
    int j = 0;
    for(int i = 0; i<n; i++){
        if(exp[i] >=  '0' && exp[i] <= '9'){
            output[j] = exp[i];
            j++;
            continue;
        }
        
        if(exp[i] == '(' || s.empty() == true){
            s.push(exp[i]);
            continue;
        }
        
        if(exp[i] == ')'){
            while(s.empty() != true && s.top() != '('){
                output[j] = s.top();
                s.pop();
                j++;
            }
            s.pop();
            continue;
        }
        
        if(prec(s.top()) < prec(exp[i])){
            s.push(exp[i]);
        } else {
            while(s.empty() != true && prec(s.top()) >= prec(exp[i])){
                output[j] = s.top();
                s.pop();
                j++;
            }
            s.push(exp[i]);
        }
        
        
    }
    
    while(s.empty() != true){
        output[j] = s.top();
        s.pop();
        j++;
    }
    
    for(int i = 0; i<strlen(output); i++){
        cout << output[i];
    }
    
    cout << endl;
    
    stack<int> s1;
    for(int i = 0; i<strlen(output); i++){
        if(output[i] >= '0' && output[i] <= '9'){
            int d = output[i] - 48;
            s1.push(d);
        } else {
            int c1 = s1.top();
            s1.pop();
            int c2 = s1.top();
            s1.pop();
            
            int d;
            
            if(output[i] == '+'){
                d = c2 + c1;
            } else if(output[i] == '-'){
                d = c2-c1;
            } else if(output[i] == '*'){
                d = c2 * c1;
            } else if(output[i] == '/'){
                d = c2 / c1;
            }
           
            s1.push(d);

        }
    }
    
    cout << s1.top() << endl;
}

int main()
{
    char exp[1000];
    cin >> exp;
    evaluatePostfix(exp);
    return 0;
}

