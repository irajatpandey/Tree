// Find Inorder Predecessor for given key in a BST

/*Given a BST, find in-order predecessor of a given key in it. 
If the given key do not lie in the BST, then return the previous greater key (if any) present in the BST.*/

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

BST* findMaximum(BST *root){
    while(root -> right)
        root = root -> right;
    return root;
}

void findInorderPredecessor(BST *root, BST *&prec, int key){
     if(root == NULL)
        return;

     if(key == root -> data){
         prec = findMaximum(root -> left);
     }  
     else if(key < root -> data){
         findInorderPredecessor(root -> left, prec, key);
     } 
     else{
         prec = root;
         findInorderPredecessor(root -> right, prec, key);

     }
     
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

    BST *prec = NULL;
    findInorderPredecessor(root, prec, 10);
     cout << prec -> data;

   
}