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

// Time Complexity O(n)
// Space Complexity O(n)
int levelOrderTraversal(BinaryTree *root){
    if(root == NULL)
        return -1;

    queue<BinaryTree*> q;
    q.push(root);
    int height = -1;

    while(true){ 

        int size = q.size();
        if(size == 0)
            break;

        while(size > 0){

            BinaryTree *temp = q.front();

            if(temp -> left)
                q.push(temp -> left);

            if(temp -> right)
                q.push(temp -> right);

            q.pop();   
            size--;        

        }
        height++;


    }
    return height;

}


int main(){

    BinaryTree *root = new BinaryTree(10); 
    root -> left  = new  BinaryTree(8); 
    root -> right      = new BinaryTree(2); 
    root -> left -> left  = new BinaryTree(3); 
    root -> left -> right = new BinaryTree(5); 
    root -> right -> left = new BinaryTree(2); 
   
    cout << levelOrderTraversal(root);



}