//bubble sort iterative
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

int len(node *head){
    node *temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    
    return count;
}

node* bubble_sort_LinkedList_itr(node* head)
{
    int a = len(head);
    for(int i = 0; i<a; i++){
        node *temp = head;
        node *prev = NULL;
        while(temp->next != NULL){
            if(temp->data > temp->next->data){
                node *forward = temp->next;
                if(prev == NULL){
                    head = forward;
                } else {
                    prev->next = temp->next;
                }
            
                
                temp->next = forward->next;
                forward->next = temp;
                prev = forward;
            } else {
                prev = temp;
                temp = temp->next;
            }
            
            
        }
  }
    
    return head;
}

int main()
{
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}

