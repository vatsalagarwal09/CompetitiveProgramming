
#include<iostream>
#include<queue>
using namespace std;


template<typename T>
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

BinaryTreeNode<int> * takeinputlevelwise()
     {

    queue<BinaryTreeNode<int>*> pendingnodes;
    int rootdata;
    cin>>rootdata;
    if(rootdata == -1)
        return NULL;

    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootdata);

    pendingnodes.push(root);


    while(!pendingnodes.empty())
    {

        BinaryTreeNode<int> * frontnode = pendingnodes.front();
        BinaryTreeNode<int> * currentnode = frontnode;
        pendingnodes.pop();

        int lchild;
        cin>>lchild;

        if(lchild!=-1)
        {
            BinaryTreeNode<int> * leftchild = new BinaryTreeNode<int>(lchild);
            pendingnodes.push(leftchild);
            currentnode->left = leftchild;

        }

        int rchild;
        cin>>rchild;

        if(rchild!=-1)
        {
            BinaryTreeNode<int> * rightchild = new BinaryTreeNode<int>(rchild);
            pendingnodes.push(rightchild);
            currentnode->right = rightchild;
        }


    }
    return root;
}

void printSpecificPattern(BinaryTreeNode<int> * root)
{
    
    queue<BinaryTreeNode<int> *> pendingNodesA;
    queue<BinaryTreeNode<int> *> pendingNodesB;
    
    pendingNodesA.push(root->left);
    pendingNodesB.push(root->right);
    
    if(root != NULL){
        cout << root->data << " ";
    }
    
    while(pendingNodesA.size() != 0 && pendingNodesB.size() != 0){
        BinaryTreeNode<int> * ele1 = pendingNodesA.front();
        pendingNodesA.pop();
        BinaryTreeNode<int> * ele2 = pendingNodesB.front();
        pendingNodesB.pop();
        
        cout << ele1->data << " ";
        cout << ele2->data << " ";
        
        if(ele1->left != NULL){
            pendingNodesA.push(ele1->left);
        }
        
        if(ele1->right != NULL){
            pendingNodesA.push(ele1->right);    
        }      
        
        if(ele2->right != NULL){
            pendingNodesB.push(ele2->right);
        }
    
        if(ele2->left != NULL){
            pendingNodesB.push(ele2->left);    
        }        
        
        if(ele2->right == NULL && ele2->left == NULL){
            continue;
        }
        

        
    }
    
    while(pendingNodesA.size() != 0){
        BinaryTreeNode<int> * ele1 = pendingNodesA.front();
        pendingNodesA.pop();
        cout << ele1->data << " ";
    }
    
    while(pendingNodesB.size() != 0){
        BinaryTreeNode<int> * ele1 = pendingNodesB.front();
        pendingNodesB.pop();
        cout << ele1->data << " ";
    }    
    
    
}

int main()
{
    BinaryTreeNode<int> * root = NULL;
    root = takeinputlevelwise();
    printSpecificPattern(root);
}

