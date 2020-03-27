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

bool isLeaf(BinaryTree *root){
   
    return(root -> left == NULL and root -> right == NULL);

}

/*Time Complexity: O(n)*/

bool checkSumTree(BinaryTree *root){
     int leftSum, rightSum;
     if(root == NULL or isLeaf(root))
        return true;

     if(checkSumTree(root -> left) and checkSumTree(root -> right)){

        if(root -> left == NULL)
            leftSum = 0;
        else if(isLeaf(root -> left))
            leftSum = root -> left -> data;
        else
            leftSum = 2 * (root -> left -> data);


        if(root -> right == NULL)
            rightSum = 0;
        else if(isLeaf(root -> right))
            rightSum = root -> right -> data;
        else
            rightSum = 2 * (root -> right -> data);

        if(root -> data == leftSum + rightSum)
            return true;
        else
            return false;


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