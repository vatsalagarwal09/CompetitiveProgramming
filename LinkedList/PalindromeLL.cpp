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

bool check_palindrome(node* head)
{
    //write your code here
    node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    
    int mid = count/2;
    
    temp = head;
    int j = 0;
    while(j < mid-1){
        temp = temp->next;
        j++;
    }
    
    node *b = temp->next;
    temp->next = NULL;
    temp = b;
    
    node *head2 = temp;
    temp = temp->next;
    head2->next = NULL;
    
    while(temp != NULL){
        node *a = temp->next;
        temp->next = head2;
        head2 = temp;
        temp = a;   
    }
    
    
    node *temp1 = head;
    node *temp2 = head2;
    
    while(temp1 != NULL || temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    return true;
}

int main()
{
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}



