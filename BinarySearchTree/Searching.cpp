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

bool search(BST *root, int key){
    BST *temp = NULL;
    while(root != NULL){
        temp = root;
        /* Duplicate data are not allowed in BST */
        if(key == root -> data)
            return true;

        if(key < root -> data)
            root = root -> left;
        else
            root = root -> right;        
    }
    return false;
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
    root -> right -> right  = new BST(22);
    root -> right ->left ->left  = new BST(11);
    root -> right ->left -> right  = new BST(16);
    root -> right ->left -> right ->left  = new BST(14);
    root -> right ->left -> right -> right  = new BST(17);

    
    printTree(root );
    if(search(root , 122))
        cout << "Found " << endl;
    else
    {
        cout << "Not found";
    }
         
   
}