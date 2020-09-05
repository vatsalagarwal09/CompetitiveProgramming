#include <iostream>
using namespace std;

template <typename T>

class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		this->data = data;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};

Node<int>* takeLLInput() {
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newnode=new Node<int>(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node<int>* func(Node<int> *head,int n) {
    	
    Node<int>* temp1 = head;
    Node<int>* prev = NULL;
    
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    
    Node<int>* temp2 = temp1;
    Node<int>* tail = temp1;
    temp1 = head;
    
    while(temp1 != tail->next){
        
        if(temp1->data == n){
            if(temp1 == tail){
                return head;
            }
            
            if(temp1 == head){
                head = head->next;
            } else {
               prev->next = temp1->next; 
            }
            
            temp2->next = temp1;
            temp1->next = NULL;
            temp2 = temp2->next;
            
            if(prev == NULL){
                temp1 = head;
            } else {
                temp1 = prev->next;
            }
            
        } else {
            prev = temp1;
            temp1 = temp1->next;
        }
    }
    
    return head;
    
}

int main() {

	Node<int>* head1 = takeLLInput();
	int n;
	cin>>n;
	printLL(func(head1,n));	
	delete head1;
	
}

