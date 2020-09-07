
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
void printLeaves(BinaryTreeNode<int> *root){
    if(root != NULL){
        printLeaves(root->left);
        printLeaves(root->right);
        if(root->left == NULL && root->right == NULL){
            cout << root->data << " ";
        } 
        
    }
}

void printRightTree(BinaryTreeNode<int> *root){
    if(root != NULL){
        if(root->right != NULL){
            printRightTree(root->right);
            cout << root->data << " ";
        } else if(root->left != NULL){
            printRightTree(root->left);
            cout << root->data << " ";
        }
    }
}

void printLeftTree(BinaryTreeNode<int> *root){
    if(root != NULL){
        if(root->left != NULL){
            cout << root->data << " ";
            printLeftTree(root->left);
        } else if(root->right != NULL){
            cout << root->data << " ";
            printLeftTree(root->right);
        }
    }
}

void solve(BinaryTreeNode<int>* root){
    if(root != NULL){
        cout << root->data << " ";
    }
    printLeftTree(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRightTree(root->right);

}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    solve(root);
}


