#include <bits/stdc++.h>
using namespace std;

class BinaryTree{
    public:
    int data;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int x){
        data = x;
        left = right = NULL;

    }

};

void inorder(BinaryTree *root, int &n, int &count){

    if(root == NULL) return;
    
    inorder(root -> left, n, count);
      count++;

    //if(n == count)
      cout << root -> data << " ";

    inorder(root -> right, n, count);


}



int main(){

     /* Construct below tree
          1
        /   \
       /     \
      2       3
            /   \
           /     \
          5       6
        /   \
       /     \
      7       8
            /   \
           /     \
          9      10
    */
   

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

    int n = 4;
    int count = 0;
    inorder(root, n, count);
}