#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

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
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node *NextLargeNumberHelper(Node *head, int n){
    if(n == 0){
        Node *newnode = new Node(1);
        newnode->next = head;
        head = newnode;
        return head;
    }
    
    Node *temp = head;
    int count = 0;
    while(count < n-1){
        temp = temp->next;
        count++;
    }
    
    if(temp->data == 9){
        temp->data = 0;
        Node *smallhead = NextLargeNumberHelper(head, n-1);
        return smallhead;
    } else {
        temp->data++;
        return head;
    }
}

Node* NextLargeNumber(Node *head) {
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    
    Node *finalAns = NextLargeNumberHelper(head, count);
    return finalAns;
    
    
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}




