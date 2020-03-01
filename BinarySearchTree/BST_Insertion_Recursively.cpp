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



BST *insertion(BST *root, int key){
     if(root == NULL){
         return new BST(key);
     }    
     if(key < root -> data){
         root -> left = insertion(root -> left, key);
     }
     else
        root -> right = insertion(root -> right, key);

     return root;   

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


void printInorder(BST *root){
    if(root == NULL)   
        return;
    printInorder(root -> left);
    cout << root -> data << " ";
    printInorder(root -> right);    
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
 
    // BST* root = new BST(10);
    // root -> left  = new BST(2);
    // root -> right = new BST(20);
    // root -> right ->left  = new BST(12);
    // root -> right -> right  = new BST(22);
    // root -> right ->left ->left  = new BST(11);
    // root -> right ->left -> right  = new BST(16);
    // root -> right ->left -> right ->left  = new BST(14);
    // root -> right ->left -> right -> right  = new BST(17);
    BST *root = NULL;
    root = insertion(root , 10);
    insertion(root , 2);
    insertion(root , 20);
    insertion(root , 12);
    insertion(root , 22);
    insertion(root , 11);
    insertion(root , 16);
    insertion(root , 14);
    insertion(root , 17);
    insertion(root , 122);


    
    printTree(root);
    printInorder(root);
   
}