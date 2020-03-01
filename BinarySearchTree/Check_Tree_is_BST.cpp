
/*
Costs
        Balanced	Unbalanced (Worst Case)
Space     O(n)	            O(n)
insert	O(lg(n))	        O(n)
lookup	O(lg(n))	        O(n)
delete	O(lg(n))	        O(n)
*/

#include <bits/stdc++.h>
using namespace std;
class BST{
    public:

    BST *left;
    BST *right;
    int data;

    BST(int x){

        left = NULL;
        right = NULL;
        data = x;   
    }

};


/* We know that an in-order traversal of a binary search tree returns the nodes in sorted order. 
Thus, to determine if given binary tree is BST or not, we can perform in-order traversal and 
keep track of the last visited node while traversing the tree and check whether its key is smaller (or smaller/equal, if duplicates are to be allowed in the tree) compared to the current key.*/



// The time complexity of this solution is O(n).
bool checkBinaryTree_isBST(BST *root, BST *&prev){
     if(root == nullptr)
        return true;
     bool leftSubTree = checkBinaryTree_isBST(root -> left, prev);
     if(root -> data <= prev -> data)
        return false;
     bool rightSubTree = checkBinaryTree_isBST(root -> right, prev);
     return leftSubTree and rightSubTree;
}




   
bool isBST(BST *root, int min, int max){

    if(root == NULL)
        return true;

    if(root -> data < min or root -> data > max)
        return false;

    return isBST(root -> left, min, root -> data) and isBST(root -> right, root -> data, max);   
}


// The time complexity of above solution is O(n) and auxiliary space used by the program is O(n).



void checkBST(BST *root){
    if(root == NULL)
        return;

    if(isBST(root, INT_MIN, INT_MAX))
        cout << "Binary Tree is BST";
    else
        cout << "Binary Tree is not BST";    


    cout << endl;


    /* another approach to check the binary tree is BST or not */

    BST *prev = new BST(INT_MIN);


    if(checkBinaryTree_isBST(root, prev))
        cout << "Binary Tree is BST";
    else
        cout << "Binary Tree is not BST";        

   

}




void printTree(BST* root)
{

    if(root == NULL) 
        return;

    cout << root -> data << " :";

    if(root -> left)
        cout << "L " << root -> left -> data << " ";

    if(root -> right)
        cout << "R " << root -> right -> data;

    
    cout << endl;

    printTree(root -> left);
    printTree(root -> right);
    return;


}

int main(){

    /* Construct below tree
          10
        /   \
       /     \
      2       20
            /   \
           /     \
          12       22
        /   \
       /     \
      11      16
            /   \
           /     \
          14      17
    */
 
    BST* root = new BST(10);
    root -> left  = new BST(2);
    root -> right = new BST(20);
    root -> right ->left  = new BST(12);
    root -> right -> right  = new BST(122);
    root -> right ->left ->left  = new BST(11);
    root -> right ->left -> right  = new BST(16);
    root -> right ->left -> right ->left  = new BST(14);
    root -> right ->left -> right -> right  = new BST(17);

    checkBST(root);
    //printTree(root);

   
}