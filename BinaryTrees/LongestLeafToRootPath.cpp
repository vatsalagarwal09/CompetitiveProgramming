
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
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

pair<vector<int>*, int> longestPathHelper(BinaryTreeNode<int> *root){
    if(root == NULL){
        pair<vector<int>*, int> p1;
        p1.first = new vector<int>();
        p1.second = 0;
        return p1;
    }
    
    if(root->left == NULL && root->right==NULL){
        pair<vector<int>*, int> ans;
        ans.first = new vector<int>();
        ans.first->push_back(root->data);
        ans.second = 1;
        return ans;
    }
    
    pair<vector<int>*, int> p2 = longestPathHelper(root->left);
    pair<vector<int>*, int> p3 = longestPathHelper(root->right);
    pair<vector<int>*, int> ans;
    if(p3.second > p2.second){
        ans.second = p3.second + 1;
        ans.first = p3.first;
    } else {
        ans.second = p2.second + 1;
        ans.first = p2.first;
    }
    ans.first->push_back(root->data);
    return ans;
}

vector<int>* longestPath(BinaryTreeNode<int>* root) {
    pair<vector<int>*, int> ans = longestPathHelper(root);
    return ans.first;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}

