#include<bits/stdc++.h>
using namespace std;
class BinaryTree{
    public:
    int data;
    BinaryTree *left, *right;
    BinaryTree(int x){
        data = x;
        left = right = NULL;
    }
};
/*
int calculateHeight(BinaryTree *root){

    if(root == NULL)
        return 0;
       
    
        int leftHeight = calculateHeight(root -> left);
        int rightHeight = calculateHeight(root -> right);
        
        if(leftHeight > rightHeight)
           return leftHeight + 1;
        else
           return  rightHeight + 1;               
   
} */

int calculateHeight(BinaryTree *root){
     if(root == NULL)
        return -1;
        return max(calculateHeight(root -> left), calculateHeight(root -> right)) + 1;  // above commented code can be written like this also
}

int main(){
    BinaryTree *root = new BinaryTree(1); 
  
    root -> left = new BinaryTree(2);  
    root -> right = new BinaryTree(3);  
    root -> left -> left = new BinaryTree(4);  
    root -> left -> right = new BinaryTree(5);  
      
    cout << "Height of tree is " << calculateHeight(root);  
      

    return 0;
}