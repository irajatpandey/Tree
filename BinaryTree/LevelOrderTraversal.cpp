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

/* Without Recursion */
void levelOrderTraversal(BinaryTree *root){
    if(root == NULL)
        return ;

    queue<BinaryTree*> q;
    q.push(root);
    int height = 0;

    

        while(!q.empty()){

            BinaryTree *temp = q.front();
           cout << temp -> data << " ";

            if(temp -> left)
                q.push(temp -> left);

            if(temp -> right)
                q.push(temp -> right);
            
            
            q.pop();   
                 
            
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