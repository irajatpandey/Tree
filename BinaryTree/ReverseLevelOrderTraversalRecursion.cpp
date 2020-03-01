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

void printReverseLevelOrderTraversal(BinaryTree *root, int Level){
    if(root == NULL)
        return;
    if(Level == 1)
     cout << root -> data << " ";
    printReverseLevelOrderTraversal(root -> left, Level - 1);
    printReverseLevelOrderTraversal(root -> right, Level - 1);        

}

/* reverse Level Order Traversal using Recursion */

/*Time Complexity: The worst case time complexity of this method is O(n^2). For a skewed tree, printLevelOrderTraversal() takes O(n) time where n is the number of nodes in the skewed tree. 
So time complexity of reverseLevelOrderTraversal() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).*/


void reverseLevelOrderTraversal(BinaryTree *root){

    int h = height(root);

    for(int i = h; i >= 0; i--) {
        printReverseLevelOrderTraversal(root, i + 1);

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
   
    reverseLevelOrderTraversal(root);



}