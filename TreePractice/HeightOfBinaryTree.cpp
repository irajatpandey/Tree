#include <bits/stdc++.h>
using namespace std;
class BinaryTree{
    public:
    int data;
    BinaryTree  *left, *right;
    int height;
    BinaryTree(int x){
        data = x;
        left = NULL;
        right = NULL;
        height = 0;

    }
    
};


int heightOfTree(BinaryTree *root){
    if(root == NULL)
        return -1;
    return max(heightOfTree(root -> left) , heightOfTree(root -> right)) + 1;
}

int main(){

    BinaryTree* root = nullptr;
 
    root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->right = new BinaryTree(4);
    root->right->left = new BinaryTree(5);
    root->right->right = new BinaryTree(6);
    root->right->left->left = new BinaryTree(7);
    root->right->left->right = new BinaryTree(8);
    

    cout << heightOfTree(root);
    

}