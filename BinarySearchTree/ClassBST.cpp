
#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

#include<queue>
class BST {
    public:
    
    BinaryTreeNode<int> *root;
    
    BST(){
        root = NULL;
    }
    
    ~BST(){
        delete root;
    }
    
    private:
    
    bool hasData(int data, BinaryTreeNode<int> *node){
        if(node == NULL){
            return false;
        }
        
        if(node->data == data){
            return true;
        } else if(node->data > data){
            return hasData(data, node->left);
        } else {
            return hasData(data, node->right);
        }
    }
    
    public:
    
    bool hasData(int data){
        return hasData(data, root);
    }
    
    private:
    BinaryTreeNode<int> *insertData(int data, BinaryTreeNode<int> *node){
        if(node == NULL){
            BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }
        
        if(node->data > data){
            node->left = insertData(data, node->left);
        } else {
            node->right = insertData(data, node->right);
        }
        
        return node;
        
    }
    
    public:
    void insert(int data){
        root = insertData(data, root);
    }
    
    private:
    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node){
        if(node == NULL){
            return NULL;
        }
        
        if(node->data > data){
            node->left = deleteData(data, node->left);
            return node;
        } else if(node->data < data){
            node->right = deleteData(data, node->right);
            return node;
        } else {
            if(node->left == NULL && node->right == NULL){
                return NULL;
            } else if(node->left == NULL){
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;                
                return temp;
            } else if(node->right == NULL){
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;                   
                return temp;
            } else {
                BinaryTreeNode<int> *temp = node->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = deleteData(temp->data, node->right);
                return node;
            }
        }
    }
    
    public:
    void deleteData(int data){
        root = deleteData(data, root);
    }
    
    private:
    void printTree(BinaryTreeNode<int> *root){
        if(root == NULL){
            return;
        }
        
        cout << root->data << ":";
        if(root->left != NULL){
            cout << "L:" << root->left->data << ",";
        }
        
        if(root->right != NULL){
            cout << "R:" << root->right->data;
        }
        cout << endl;
        
        if(root->left != NULL){
            printTree(root->left);    
        }
        
        if(root->right != NULL){
            printTree(root->right);    
        }         
    }
    
    public:
    void printTree(){
        printTree(root);
    }
};

int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}


