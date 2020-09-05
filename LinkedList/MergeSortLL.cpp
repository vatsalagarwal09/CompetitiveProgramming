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

node* mergeSort(node *head) {
    
    if(head->next == NULL){
        return head;
    }

    node *slow = head;
    node *fast = slow->next;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    node *secondHead = slow->next;
    slow->next = NULL;
    //call merge sort on two halves
    node *head1 = mergeSort(head);
    node *head2 = mergeSort(secondHead);
   
    //merger linked list
    node *finalHead = NULL;
    node *finalTail = NULL;
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(finalHead == NULL){
                finalHead = head1;
                finalTail = head1;
            } else {
                finalTail->next = head1;
                finalTail = finalTail->next;
            }
            
            head1 = head1->next;
        } else {
            if(finalHead == NULL){
                finalHead = head2;
                finalTail = head2;
            } else {
                finalTail->next = head2;
                finalTail = finalTail->next;
            }
            
            head2 = head2->next;            
        }
    }
    
    if(head1 == NULL){
        finalTail->next = head2;
    } else {
        finalTail->next = head1;
    }
    
    return finalHead;
}

int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}


