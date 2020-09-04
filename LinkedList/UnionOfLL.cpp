#include <iostream>
using namespace std;

template <typename T>
class ListNode {
    public:
    T data;
    ListNode<T> *next;
    ListNode<T>(T data)
    {
        this -> data=data;
        next = NULL;
    }
};

 ListNode<int>* createlist()
	{
	    ListNode<int> *head=NULL;
		ListNode<int> *rear=NULL;
		int data;
		cin>>data;
		while(data!=-1)
		{
			ListNode<int> *newnode=new ListNode<int>(data);
			if(head==NULL)
			{
				head=newnode;
				rear=head;
			}
			else
			{
				rear->next=newnode;
				rear=rear->next;
			}
			cin>>data;
		}
		return head;
	}

    void print(ListNode<int> * head)
	{
		while(head!=NULL)
		{
			cout<<head->data<<endl;
			head=head->next;
		}
	}


#include<unordered_map>
   ListNode<int> *unionOf2LL(ListNode<int> *head1,ListNode<int> *head2)
	{
       if(head1 == NULL){
           return head2;
       }
	    //WRITE YOUR CODE HERE
       unordered_map<int, int> m;
       ListNode<int> *finalHead = head1;
       ListNode<int> *temp = head1;
      // m[temp->data] = 1;
       
       while(temp != NULL && temp->next!=NULL){
           m[temp->data]++;
           temp = temp->next;
       }
       m[temp->data]++;
       
       
       
       
       
//        ListNode<int> *finalHead=new ListNode<int>(head1->data);
//        ListNode<int> *temp = head1->next;
//        m[head1->data] = 1;
//        while(temp->next != NULL){
//            ListNode<int> *newnode2 = new ListNode<int>(temp->data);
//            m[temp->data] = 1;
//            temp = temp->next;
//        }       
       
       
       
       ListNode<int> *temp2 = head2;
       while(temp2 != NULL){
           if(m.count(temp2->data) == 0 || m[temp2->data] == 0){
               ListNode<int> *newnode=new ListNode<int>(temp2->data);
               temp->next = newnode;
               temp = newnode;                 
           } else {
               m[temp2->data]--;
           }
           temp2 = temp2->next; 
       }
       
       temp->next = NULL;
       
       return finalHead;
	}

int main()
{
   ListNode<int> *head1=createlist();
   ListNode<int> *head,*head2=createlist();
   head=unionOf2LL(head1,head2);
   print(head);
}

