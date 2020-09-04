//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
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

node *reverseLL(node *smallHead, int k){
    if(smallHead == NULL || smallHead->next == NULL || k == 1){
        return smallHead;
    }
    
    node *smallAns = reverseLL(smallHead->next, k-1);
    node *tail = smallHead->next;
    tail->next = smallHead;
    smallHead->next = NULL;
    
    return smallAns;
}

node* kReverse(node*head,int n)
{
    //write your code here
    node *temp = head;
    node *loopcurrent = NULL;
    while(temp != NULL){
        node *current = temp;
        int count = 0;
        while(count < n && current != NULL){
            count++;
            current = current->next;
        }
        node *smallAns = reverseLL(temp->next, n-1);
        if(temp == head){
            head = smallAns;
        } else {
            loopcurrent->next = smallAns;
        }
        
        node *tail = temp->next;
        tail->next = temp;
        temp->next = current;  
        loopcurrent = temp;
        temp = current;
    }
    
    return head;
}


int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}

