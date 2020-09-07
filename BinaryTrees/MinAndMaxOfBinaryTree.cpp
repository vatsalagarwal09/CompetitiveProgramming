
#include <iostream>
#include <queue>

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

class PairAns {
    public :
    int min;
    int max;
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

#include<bits/stdc++.h>
PairAns minMax(BinaryTreeNode<int> *root) {
    if(root == NULL){
        PairAns p1;
        p1.max = INT_MIN;
        p1.min = INT_MAX;
        return p1;
    }
    
    PairAns p1;
    p1.min = root->data;
    p1.max = root->data;
    
    PairAns p2 = minMax(root->left);
    
    if(p1.max < p2.max){
        p1.max = p2.max;
    } 
    
    if(p1.min > p2.min){
        p1.min = p2.min;
    }
    
    PairAns p3 = minMax(root->right);
    if(p1.max < p3.max){
        p1.max = p3.max;
    } 
    
    if(p1.min > p3.min){
        p1.min = p3.min;
    }
    
    return p1;
    
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    PairAns ans = minMax(root);
    cout << ans.max << " " << ans.min << endl;
}

