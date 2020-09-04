#include<iostream>
using namespace std;

template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		//(*this).data = data;
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
        if(head==NULL) {
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


Node<int> *reverse(Node<int> *head3){
    Node<int> *temp = head3->next;
    Node<int> *a = temp->next;
    temp->next = head3;
    head3->next = NULL;
    
    while(a != NULL){
        head3 = temp;
        temp = a;
        a = a->next;
        
        temp->next = head3;
        
    }
    
    return temp;
    
}


void AlternatingSplit(Node<int>* head) {
	// Write your code here
    Node<int> *temp = head;
   
    Node<int> *head1 = new Node<int>(head->data);
    Node<int> *temp1 = head1;
    temp = temp->next;
    
    Node<int> *head2 = new Node<int>(temp->data);
    Node<int> *temp2 = head2;
    temp = temp->next;
    
    while(temp != NULL){
        Node<int> *newnode=new Node<int>(temp->data);
        temp1->next= newnode;
        temp1 = temp1->next;
        temp = temp->next;  
        
        if(temp!= NULL){
            Node<int> *newnode=new Node<int>(temp->data);
            temp2->next = newnode;
            temp2 = temp2->next;
            temp = temp->next;            
        }

    }
    
    temp1->next = NULL;
    temp2->next = NULL;
    
     head1 = reverse(head1);
     head2 = reverse(head2);

    temp1 = head1;
    temp2 = head2;
    
    while(temp1 != NULL){
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    
    cout << endl;
    
    while(temp2 != NULL){
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
}

int main()
{ 
	Node<int>* head=takeLLInput();

	AlternatingSplit(head);
	
}


