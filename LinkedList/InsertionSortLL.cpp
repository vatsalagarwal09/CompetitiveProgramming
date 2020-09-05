//insertion sort iterative
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
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
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* insertion_sort_LinkedList_itr(node* head)
{
	if(head == NULL){
		return NULL;
	}
	
	node *current = head->next;
	node *prev = head;
	
	while(current != NULL){
		int k = 0;
		node *temp = head;
		node *p = head;
		while(temp != current){
			if(current->data < temp->data){
				node *t = current->next;
				if(temp == head){
					head = current;
					prev->next = t;
					current->next = temp;
					current = t;
				} else {
					p->next = current;
					current->next = temp;
					prev->next = t;
					current = t;
				}
				k = 1;
				break;
			} else {
				p = temp;
				temp = temp->next;
			}
		}
		if(k==0){
			prev = current;
			current = current->next;
		}
	}
	
	return head;

}


int main()
{
    node* head=takeinput();
    head=insertion_sort_LinkedList_itr(head);
    print(head);
}

