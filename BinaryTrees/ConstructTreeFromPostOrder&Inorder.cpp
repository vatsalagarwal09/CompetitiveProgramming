
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
BinaryTreeNode<int>* getTree(int *postorder, int *inorder, int pos, int poe, int ins, int ine){
    if(pos > poe){
        return NULL;
    }
    
    int rootData = postorder[poe];
    int rootIndex = -1;
    int i = 0;
    for(i = ins; i<=ine; i++){
        if(inorder[i] == rootData){
            break;
        }
    }
    
    rootIndex = i;
    
    int lins = ins;
    int line = rootIndex-1;    
    int lpos = pos;
    int lpoe = line - lins + lpos;
    int rpos = lpoe + 1; 
    int rpoe = poe-1;
    int rins = rootIndex+1;
    int rine = ine;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = getTree(postorder, inorder, lpos, lpoe, lins, line);
    root->right = getTree(postorder, inorder, rpos, rpoe, rins, rine);
    
    
    return root;
}


BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    return getTree(postorder, inorder, 0, postLength-1, 0, postLength-1);
}


int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
		cin>>post[i];
    for(int i=0;i<size;i++)
		cin>>in[i];
    BinaryTreeNode<int>* root = getTreeFromPostorderAndInorder(post, size, in, size);
    printLevelATNewLine(root);
}


