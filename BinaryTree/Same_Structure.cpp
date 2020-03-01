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

/*
Algorithm:

    1.If both trees are empty then return 1.
    2.Else If both trees are non-empty:
        Check left subtrees recursively i.e., call isSameStructure(tree1->left_subtree, tree2->left_subtree)
        Check right subtrees recursively i.e., call isSameStructure(tree1->right_subtree, tree2->right_subtree)
        If the value returned in above two steps are true then return 1.
    3.Else return 0 (one is empty and other is not).

    Time Complexity: O(n)
    Spacet Complexity: O(n)

*/

bool isSame(BinaryTree *root1, BinaryTree *root2){
      if(root1 == NULL and root2 == NULL)
        return true;
      
       if(root1 == NULL or root2 == NULL)
        return false;

      return isSame(root1-> left, root2 -> left) and isSame(root1 -> right, root2 -> right);  

}
int main(){

    BinaryTree *root1   = new  BinaryTree(1); 
    root1 ->left = new  BinaryTree(2); 
    root1 ->right = new  BinaryTree(3); 
    root1 ->left -> left = new  BinaryTree(4); 
    root1 ->right -> left = new  BinaryTree(5); 
    root1 ->right -> right = new  BinaryTree(8); 
    root1 ->right -> left -> left = new  BinaryTree(6); 
    root1 ->right -> left -> right = new  BinaryTree(7); 
    root1 ->right -> right -> left = new  BinaryTree(9); 
    root1 ->right -> right -> right = new  BinaryTree(10); 


    BinaryTree *root2   = new  BinaryTree(10); 
    root2 ->left = new  BinaryTree(20); 
    root2 ->right = new  BinaryTree(30); 
    root2 ->left -> left = new  BinaryTree(40); 
    root2 ->right -> left = new  BinaryTree(50); 
    root2 ->right -> right = new  BinaryTree(80); 
    root2 ->right -> left -> left = new  BinaryTree(60); 
    root2 ->right -> left -> right = new  BinaryTree(70); 
    root2 ->right -> right -> left = new  BinaryTree(90); 
    root2 ->right -> right -> right = new  BinaryTree(100); 


    if(isSame(root1, root2))
        cout << "Same Structure";
    else
        cout << "Different Structure"   ;

   

}