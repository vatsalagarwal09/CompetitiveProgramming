#include <iostream>
#include<bits/stdc++.h>
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

int decimal(Node<int> *head) {

    Node<int> *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
     
    temp = head;
    int sum = 0;
    while(temp != NULL){
        sum += pow(2, count-1) * (temp->data);
        temp = temp->next;
        count--;
    }
    
    return sum;
    
}

int main() {

	Node<int>* head1 = takeLLInput();
	
	
	cout<<decimal(head1)<<endl;
	
	delete head1;
	
}

