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

node* swap_nodes(node *head,int i,int j)
{
    //write your code here
    if(j<i){
        int a = j;
        j = i;
        i = a;
    }
    
    node *temp1 = head;
    node *temp2 = head;
    
    int count = 0;
    while(count < i-1){
        temp1 = temp1->next;
        count++;
    }
    
    count = 0;
    while(count < j-1){
        temp2 = temp2->next;
        count++;
    }    
    
    if(i==0 && j==1){
        node *a = head;
        head = temp2->next;
        a->next = temp2->next->next;
        head->next = a;
        return head;
    }
    
    if(i==0){
        node *a = head;
        head = temp2->next;
        temp2->next = a;
        
        node *b = head->next;
        head->next = a->next;
        a->next = b;
        
        return head;
    }
    
    
    if(j-i == 1){
        node *a = temp1->next;
        temp1->next = temp2->next;
        
        node *b = temp1->next->next;
        temp1->next->next = a;
        a->next = b;
        
        return head;
    }

    
    node *a = temp1->next;
    temp1->next = temp2->next;
    node *b = a->next;
    temp2->next = a;
    
    
    a->next = temp1->next->next;
    temp1->next->next = b;
    
    return head;
    
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
