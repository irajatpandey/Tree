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
BST *search(BST *root, int key){

    if (root == NULL || root-> data == key) 
       return root; 
  
     if(key < root -> data)
        return search(root -> left, key);
     else
        return search(root -> right, key);

    
}

BST* minimumKey(BST* curr)
{
    while(curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

BST* maximumKey(BST* ptr)
{
    while(ptr->right != nullptr) {
        ptr = ptr->right;
    }
    return ptr;
}
 
//  The time complexity of above solution is O(n).
void deletion(BST *&root, int key){
     // base case: key not found in tree
    if (root == nullptr)
        return;
 
    // if given key is less than the root node, recur for left subtree
    if (key < root->data)
        deletion(root->left, key);
 
    // if given key is more than the root node, recur for right subtree
    else if (key > root->data)
        deletion(root->right, key);

    else
    {
        // Case 1: node to be deleted has no children (it is a leaf node)
        if (root->left == nullptr && root->right == nullptr)
        {
            // deallocate the memory and update root to null
            delete root;
            root = nullptr;
        }
 
        // Case 2: node to be deleted has two children
        else if (root->left && root->right)
        {
            // find its in-order predecessor node
            BST *predecessor = maximumKey(root->left);
 
            // Copy the value of predecessor to current node
            root->data = predecessor->data;
 
            // recursively delete the predecessor. Note that the
            // predecessor will have at-most one child (left child)
            deletion(root->left, predecessor->data);
        }
 
        // Case 3: node to be deleted has only one child
        else
        {
            // find child node
            BST* child = (root->left)? root->left: root->right;
            BST* curr = root;
 
            root = child;
 
            // deallocate the memory
            delete curr;
        }
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

    deletion(root, 22);
    //printTree(root);
   
}