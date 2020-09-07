
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

BinaryTreeNode<int>* buildTreeHelper(int *preorder, int *inorder, int prs, int pre, int ins, int ine){
    if(ins > ine){
        return NULL;
    }
    
    int rootData = preorder[prs];
    int rootIndex = -1;
    int i = 0;
    for(i = ins; i<ine; i++){
        if(inorder[i] == rootData){
            break;
        }
    }
    
    rootIndex = i;
    
    int lins = ins;
    int line = rootIndex - 1;
    int lprs = prs + 1;
    int lpre = line - lins + lprs;
    int rins = rootIndex + 1;
    int rine = ine;
    int rprs = lpre + 1;
    int rpre = pre;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(preorder, inorder, lprs, lpre, lins, line);
    root->right = buildTreeHelper(preorder, inorder, rprs, rpre, rins, rine);
    
    return root;
}


BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
    return buildTreeHelper(preorder, inorder, 0, inLength-1, 0, inLength-1);
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
		cin>>pre[i];
    for(int i=0;i<size;i++)
		cin>>in[i];
    BinaryTreeNode<int>* root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}

