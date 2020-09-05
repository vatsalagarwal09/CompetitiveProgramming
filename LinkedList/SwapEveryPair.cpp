#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
    	if(next) 
	    delete next;
    }
};

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node*temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* swapEveryPair(Node *head) {
    //write your code here
    Node *temp = head;
    
    Node *a = NULL;
    while(temp != NULL && temp->next != NULL){
        if(temp == head){
            head = temp->next;
        } else {
            a->next = temp->next;
        }

        a = temp->next;
        Node *b = a->next;
        a->next = temp;
        temp->next = b;
        a = temp;
        temp = b;
        
    }
    
    return head;
}

int main() {
    Node* head = takeinput();
    head = swapEveryPair(head);
    print(head);
    delete head;
    return 0;
}


