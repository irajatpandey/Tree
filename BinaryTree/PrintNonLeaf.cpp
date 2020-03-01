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

void printNonLeaf(BinaryTree *root  ){

    if(root   == NULL)
        return;

    if(root   -> left == NULL and root   -> right == NULL)
        return;
    else
        cout <<  root   -> data << " ";    
    printNonLeaf(root   -> left);
    printNonLeaf(root   -> right);        
}


int main(){

    BinaryTree *root            = new  BinaryTree(1); 
    root ->left                 = new BinaryTree(2); 
    root ->right                = new BinaryTree(3); 
    root ->left -> left         = new BinaryTree(4); 
    root ->right -> left        = new BinaryTree(5); 
    root ->right -> right       = new  BinaryTree(8); 
    root ->right -> left -> left = new BinaryTree(6); 
    root ->right -> left -> right = new BinaryTree(7); 
    root ->right -> right -> left = new BinaryTree(9); 
    root ->right -> right -> right = new  BinaryTree(10); 
   
   printNonLeaf(root );

}