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

int sumTree(BinaryTree *root){

    if(root == NULL) return 0;

    int oldValue = root -> data;

    root -> data = sumTree(root -> left) + sumTree(root -> right);

    return root -> data + oldValue;

}

void inorder(BinaryTree *root){
    if(!root) return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}




int main(){

    BinaryTree *root = new BinaryTree(10); 
    root -> left  = new  BinaryTree(8); 
    root -> right      = new BinaryTree(2); 
    root -> left -> left  = new BinaryTree(3); 
    root -> left -> right = new BinaryTree(5); 
    root -> right -> left = new BinaryTree(2); 
   
    sumTree(root);

    inorder(root);


}