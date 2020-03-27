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
    return (root -> left == NULL and root -> right == NULL);
}

/*Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n).*/
bool checkLeaveNodesLevel(BinaryTree *root, int *levelOfNode, int level){
    if(root == NULL) return true;

    if(isLeaf(root)){

        if(*levelOfNode == 0){

            *levelOfNode = level;
            return true;
        }

        return *levelOfNode ==  level;
    }

    return (checkLeaveNodesLevel(root -> left, levelOfNode, level + 1) and checkLeaveNodesLevel(root -> right, levelOfNode, level + 1));


}


int main(){

    BinaryTree *root = new BinaryTree(12); 
    root->left = new BinaryTree(5); 
    root->left->left = new BinaryTree(3); 
    root->left->right = new BinaryTree(9); 
    root->left->left->left = new BinaryTree(1); 
    root->left->right->left = new BinaryTree(1); 
    
    int level = 0;
    int levelOfNode = 0;

    if(checkLeaveNodesLevel(root, &levelOfNode, level))
        cout << "True";
    else
        cout << "False";
   



}