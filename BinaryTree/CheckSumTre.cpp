#include <bits/stdc++.h>
using namespace std;
class BinaryTree{
    public:
    int data;
    BinaryTree  *left, *right;

    BinaryTree(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
    
};

int sum(BinaryTree *root){

	if(root == NULL)
		return 0;
	return root -> data + sum(root -> left) + sum(root -> right);
}

/*Get the sum of nodes in left subtree and right subtree. 
Check if the sum calculated is equal to root’s data. Also, recursively check if the left and right subtrees are SumTrees.*/

/*Time Complexity: O(n^2) in worst case. Worst case occurs for a skewed tree.*/
/*For every node we are calulating left sub tree and right sub tree so it will take o(n) * o(n) = o(n ^ 2);p*/


bool checkSumTree(BinaryTree *root){

    if(root == NULL or (root -> left == NULL and root -> right == NULL)) 
    	return true;

    int oldValue = root -> data;

    root -> data = sum(root -> left) + sum(root -> right);
    if(root -> data == oldValue){
    	if(checkSumTree(root -> left) and checkSumTree(root -> right))
    		return true;
    } 

    return false;

}

void inorder(BinaryTree *root){
    if(!root) return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}




int main(){

    BinaryTree *root  =  new BinaryTree(26); 
    root->left         = new BinaryTree(10); 
    root->right        = new BinaryTree(3); 
    root->left->left   = new BinaryTree(4); 
    root->left->right  = new BinaryTree(6); 
    root->right->right = new BinaryTree(3); 
   
    if(checkSumTree(root)) cout << "True";
    else cout << "False";



}