
#include <iostream>
#include <queue>

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


class Pair{
    public:
    Node<int> *head;
    Node<int> *tail;
    
    Pair(){
        head = NULL;
        tail = NULL;
    }

};

Pair construtBSTHelper(BinaryTreeNode<int>* root){
    if(root == NULL){
        Pair p1;
        p1.head = NULL;
        p1.tail = NULL;
        return p1;
    }
    
    Pair left = construtBSTHelper(root->left);
    Pair right = construtBSTHelper(root->right);
    
    Node<int> *newnode = new Node<int>(root->data);
    
    if(left.head == NULL){
        left.head = newnode;
        left.tail = newnode;
        if(right.head == NULL){
            right.head = newnode;
            right.tail = newnode;            
        } else {
            newnode->next = right.head;
        }
    } else {
        left.tail->next = newnode;
        newnode->next = right.head; 
    }

    Pair ans;
    ans.head = left.head;
    ans.tail = right.tail;  

    return ans;
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    Pair ans = construtBSTHelper(root);
    return ans.head;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    
}

