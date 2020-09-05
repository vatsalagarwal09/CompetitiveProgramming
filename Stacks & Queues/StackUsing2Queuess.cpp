 #include<iostream>
 #include<stack>
 using namespace std;
 
 int main(){
    stack<int> s;
    int choice, input;
 
    while(true){
 
        cin >> choice;
 
        switch(choice){
            case 1: // Push element
                cin >> input;
                s.push(input);
                break;

            case 2: // Pop element
                cout << s.pop() << "\n";
                break;
            
            case 3: // Reads the top element
                cout << s.top() << "\n";
                break;

            case 4 : // Size
                cout << s.getSize() << endl;
                break;

            case 5 : // Test
                while(!s.q1 -> empty()) {
                    cout << s.q1 -> front() << " ";
                    s.q1 -> pop();
                }
                break;
                return 0;
 
            default:
                return 0;
                break;
        }
    }
 }


#include<queue>
using namespace std;
template <typename T>
class stack {

    public:

    queue<T> *q1;
    queue<T> *q2;
    
    stack(){
        q1 = new queue<T>();
        q2 = new queue<T>();
    }
    
    void push(T element){
        q1->push(element);
    }
    
    T pop(){
        if(q1->size() == 0){
            return 0;
        }
        int count = 0;
        while(q1->size()!= 1){
            q2->push(q1->front());
            q1->pop();
            count++;
        }
        
        T ans = q1->front();
        q1->pop();
        queue<T> *q3 = q2;
        q2 = q1;
        q1 = q3;
       // swap(q1, q2);
        return ans;
    }
    
    T top(){
        if(q1->size() == 0){
            return 0;
        }
        int count = 0;
        while(q1->size() != 1){
            q2->push(q1->front());
            q1->pop();
            count++;
        }
        
        T ans = q1->front();
        q2->push(q1->front());
        q1->pop();
        queue<T> *q3 = q2;
        q2 = q1;
        q1 = q3;        
        return ans;        
        
    }
    
    int getSize(){
        return q1->size();
    }
};

