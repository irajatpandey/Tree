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





void printLeaf(BinaryTree *root){
	 if(root == NULL)  return;

	if(root -> left == NULL and root -> right == NULL)
	 	cout << root -> data << " ";
	 printLeaf(root -> left);

	 printLeaf(root -> right);

}

void printLeftBoundary(BinaryTree *root){
	 if(root == NULL)  return;

	 	
	 if(root -> left){
	 	cout << root -> data << " ";
	 	printLeftBoundary(root -> left);
	 } 
	 else if(root -> right){
	 	cout << root -> data << " ";
	 	printLeftBoundary(root -> right);
	 } 
}

void printRightBoundary(BinaryTree *root){
	 if(root == NULL)  return;
	 

	 if(root -> right != NULL){
	 printRightBoundary(root -> right);
	 cout << root -> data << " ";}

	 else if(root -> left != NULL){
	 printRightBoundary(root -> left);
	 cout << root -> data << " ";}

	

}
/*
     This problem can be solved using 4 steps
    1. There is a function name, printBoundaryNodes() which takes root as parameter. We will print the root -> data
    2. call printBoundaryLeft() will print all the element on the left hand side but not the leaf node
    3. call printLeaves() will print all the leaves nodes of the binary tree.
    4. call printBoundaryRight() will take care of right subTree and print the element which are at boundary.
        Note: In step 4, we have to recursively call the method and then print the data unlike step 2
*/

// Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n).
// Auxiliary Space: O(n), due to the stack space during recursive call.


void printBoundary(BinaryTree *root){
	 if(root == NULL)  return;

	 cout << root -> data << " ";
	 printLeftBoundary(root -> left);
	 printLeaf(root -> left);
	 printLeaf(root -> right);

	 printRightBoundary(root -> right);


	
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

	    printBoundary(root);


	return 0;    
}
