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

void preOrder(BinaryTree *root){

    if(!root)
        return;

    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);

}


// Time complexity O(n);
// Space Complexity O(n);
bool isMirrorTree(BinaryTree* root1, BinaryTree *root2){
    if(root1 == NULL and root2 == NULL)
        return true;
    if(root1 != NULL and root2 != NULL)
    return(root1 -> data == root2 -> data) and isMirrorTree(root1 -> left, root2 -> right) and isMirrorTree(root1 -> right, root2 -> left);
    
    return false;
    
}

int main(){

    BinaryTree *root   = new  BinaryTree(1); 
    root ->left = new  BinaryTree(2); 
    root ->right = new  BinaryTree(3); 
    root ->left -> left = new  BinaryTree(4); 
    root ->right -> left = new  BinaryTree(5); 
    root ->right -> right = new  BinaryTree(8); 
    root ->right -> left -> left = new  BinaryTree(6); 
    root ->right -> left -> right = new  BinaryTree(7); 
    root ->right -> right -> left = new  BinaryTree(9); 
    root ->right -> right -> right = new  BinaryTree(10); 



    BinaryTree *root2   = new  BinaryTree(1); 
    root2 ->left = new  BinaryTree(2); 
    root2 ->right = new  BinaryTree(3); 
    root2 ->left -> left = new  BinaryTree(4); 
    root2 ->right -> left = new  BinaryTree(15); 
    root2 ->right -> right = new  BinaryTree(18); 
    root2 ->right -> left -> left = new  BinaryTree(6); 
    root2 ->right -> left -> right = new  BinaryTree(7); 
    root2 ->right -> right -> left = new  BinaryTree(9); 
    root2 ->right -> right -> right = new  BinaryTree(10); 

   cout << isMirrorTree(root, root2);
   
  

  

}