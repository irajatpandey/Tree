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

int height(BinaryTree *root){
    if(root == NULL)
        return -1;
    return max(height(root -> left), height(root -> right)) + 1;    

}

void printLevelOrderTraversal(BinaryTree *root, int i){
    if(root == NULL)
        return;
    if(i == 1)
        cout << root -> data << " ";
    printLevelOrderTraversal(root -> left, i - 1);
    printLevelOrderTraversal(root -> right, i - 1);        

}

void levelOrderTraversal(BinaryTree *root){
    int h = height(root);
    for(int i = 0; i <= h; i++) {
        printLevelOrderTraversal(root, i + 1);
        cout << endl;
    }
    

}


int main(){

    BinaryTree *root =      new BinaryTree(10); 
    root -> left    =       new BinaryTree(8); 
    root -> right      =    new BinaryTree(2); 
    root -> left -> left  = new BinaryTree(3); 
    root -> left -> right = new BinaryTree(5); 
    root -> right -> left = new BinaryTree(2); 
   
    levelOrderTraversal(root);
   

}

