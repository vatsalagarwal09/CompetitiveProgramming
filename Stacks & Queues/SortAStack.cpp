#include <iostream>
#include <stack>
using namespace std;
void sortStack(stack<int> &s){

    stack<int> tempStack;
    while(s.empty() == false){
        int temp = s.top();
        s.pop();
        while(tempStack.empty() != true && tempStack.top() > temp){
            int x = tempStack.top();
            tempStack.pop();
            s.push(x);
        }
        
        tempStack.push(temp);
    }
    
    while(tempStack.empty() == false){
        s.push(tempStack.top());
        tempStack.pop();
    }
    
    while(s.empty() == false){
        cout << s.top() << " ";
        s.pop();
    }
}


int main() {
    stack<int> input;
    int size, value;
    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> value;
        input.push(value);
    }
    sortStack(input);
    while(!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
}

