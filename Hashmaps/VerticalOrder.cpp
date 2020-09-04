#include<iostream>
#include <queue>
#include<cmath>
#include<map>
#include<vector>
using namespace std;

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

    void VerticalOrder(BinaryTreeNode<int> *root, int height, map<int, vector<int>> &m){
        if(root == NULL){
            return;
        }
        
        m[height].push_back(root->data);
        
        VerticalOrder(root->left, height-1, m);
        VerticalOrder(root->right, height+1, m);
    }

    void printTree(BinaryTreeNode<int> *root){
        map<int, vector<int>> m;
        int height = 0;
        VerticalOrder(root, height, m);
        
        map<int, vector<int>>::iterator it;
        for(it=m.begin(); it!=m.end(); it++){
            for(int i = 0; i<it->second.size(); i++){
                cout << it->second[i] << " ";
            }
            cout << endl;
        }
    }


	void printBinaryTreeVerticalOrder(BinaryTreeNode<int>* root) {	 
		
	// Following is the structure of the Binary Tree node class
	/*
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
	*/
     	
        printTree(root);
     	
 	}

BinaryTreeNode<int>* takeInputLevelWise() {
    int data;
//  cout << "Enter root : ";
    cin >> data;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);

    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
        BinaryTreeNode<int> *current = pendingNodes.front();
        pendingNodes.pop();

        int leftData, rightData;
    //  cout << "Enter left child of : " << current -> data << " : ";
        cin >> leftData;

        if(leftData != -1) {
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftData);
            current -> left = left;
            pendingNodes.push(left);
        }

    //  cout << "Enter right child of  " << current -> data << " : ";
        cin >> rightData;

        if(rightData != -1) {
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightData);
            current -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;

}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBinaryTreeVerticalOrder(root);
    return 0;
}


