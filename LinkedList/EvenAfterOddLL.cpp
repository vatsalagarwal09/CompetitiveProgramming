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

node* arrange_LinkedList(node* head)
{
    //write your code here
    node *temp = head;
   
    node *head1 = NULL;
    node *temp1 = NULL;
    node *head2 = NULL;
    node *temp2 = NULL;
    
    while(temp != NULL){
        node *newnode=new node(temp->data);
        
        if(temp->data % 2 == 0){
            if(head1 == NULL){
                head1 = newnode;
                temp1 = head1;
            } else {
                temp1->next = newnode;
                temp1 = temp1->next;
            }

        } else {
            if(head2 == NULL){
                head2 = newnode;
                temp2 = head2;
            } else {
                temp2->next = newnode;
                temp2 = temp2->next;                   
            }   
        }
        temp = temp->next;
    }
    
    if(head2 == NULL){
        return head1;
    }
    
    temp2->next = head1;
    
    return head2;
    
}
int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}

