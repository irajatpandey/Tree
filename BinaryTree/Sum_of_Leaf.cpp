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

int sumOfLeaf(BinaryTree *root){
    if(root == NULL)
        return 0;
    if(root -> left == NULL and root -> right == NULL)
        return root -> data;   
    else
        return sumOfLeaf(root -> left) + sumOfLeaf(root -> right);
           
}

int main(){

    BinaryTree *root = new BinaryTree(10); 
    root -> left  = new  BinaryTree(8); 
    root -> right      = new BinaryTree(2); 
    root -> left -> left  = new BinaryTree(3); 
    root -> left -> right = new BinaryTree(5); 
    root -> right -> left = new BinaryTree(2); 
   
    cout << sumOfLeaf(root);

}