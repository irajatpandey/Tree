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




void printRightView(BinaryTree *root, int level, int *maxSize){

    if(root == NULL)
        return;
    if(level >= (*maxSize)){
        cout << root -> data << " ";
        (*maxSize)++;
    }   

    printRightView(root -> right, level + 1, maxSize);
    printRightView(root -> left, level + 1, maxSize);
    




}

// Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n).
// Auxiliary Space: O(n), due to the stack space during recursive call.


void rightView(BinaryTree *root){
    int maxSize = 0;
    printRightView(root, 0, &maxSize);
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

   rightView(root);

}