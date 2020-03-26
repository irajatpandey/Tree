#include <bits/stdc++.h>
using namespace std;

class BinaryTree{
 public:
	int data;
	BinaryTree *left, *right;


	BinaryTree(int x){
		data = x;
		left = right = NULL;
	}

};


void inorder(BinaryTree *root, vector<int> &in){
	if(root == NULL) return;
	inorder(root -> left, in);
	cout << root -> data << " ";
	in.push_back(root -> data);
	inorder(root -> right, in);

}

void preorder(BinaryTree *root, vector<int> &pre){
	if(root == NULL) return;
	cout << root -> data << " ";
	pre.push_back(root -> data);
	inorder(root -> left, pre);
	inorder(root -> right, pre);
}

BinaryTree* buildTreeHelper(vector<int> in, vector<int> pre, int inStart, int inEnd, int preStart, int preEnd){
			if(inStart > inEnd or preStart > preEnd) return NULL;

			int rootData = pre[preStart];

			int rootIndex = -1;

			for(int i = inStart; i <= inEnd; i++){
				if(in[i] == rootData){
				   rootIndex = i;
				   break;
				}
			}
			

			int leftInorderStart = inStart;
			int leftInorderEnd = rootIndex - 1;

			

			int leftPreorderStart = preStart + 1;
			int leftPreorderEnd = leftInorderEnd - leftInorderStart + leftPreorderStart;

			int rightPreorderStart = leftPreorderEnd  + 1;
			int rightPreorderEnd = preEnd;

			int rightInorderStart = rootIndex + 1;
			int rightInorderEnd = inEnd;
			BinaryTree *root = new BinaryTree(rootData);

			root -> left = buildTreeHelper(in, pre, leftInorderStart, leftPreorderEnd, leftPreorderStart, leftPreorderEnd);
			root -> right = buildTreeHelper(in, pre, rightInorderStart, rightPreorderEnd, rightPreorderStart, rightPreorderEnd);
		
			return root;

		}


void take_inorder(BinaryTree *root){

	if(root == NULL) return;

	
	take_inorder(root -> left);
	cout << root -> data << " ";
	take_inorder(root -> right);

}
void buildTree(BinaryTree *root){

	vector<int> in;
	vector<int> pre;

	inorder(root, in); cout << endl;
	preorder(root, pre); cout << endl;
	int size = in.size();

	BinaryTree *buildRoot = buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
	take_inorder(buildRoot);




}




int main(){

	   /* Construct below tree
          1
        /   \
       /     \
      2       3
            /   \
           /     \
          5       6
        /   \
       /     \
      7       8
    */

	    BinaryTree* root = new BinaryTree(1);
	    root -> left = new BinaryTree(2);
	    root -> right = new BinaryTree(3);
	    root -> right -> left = new BinaryTree(5);
	    root -> right -> right = new BinaryTree(6);
	    root -> right -> left -> left = new BinaryTree(7);
	    root -> right -> left -> right = new BinaryTree(8);

	    cout << "Spiral Order traversal of binary tree is \n";
	    buildTree(root);


	return 0;    
}