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

/*Recursive Approach*/
/* 
    The idea is to use any of the tree traversals to traverse the tree and while traversing check if the current node matches with the given node. 
    Print YES if any node matches with the given node and stop traversing further and 
    if the tree is completely traversed and none of the node matches with the given node then print NO.

*/
bool isPresent(BinaryTree *root, int ele){
    if(root == NULL)
        return false;

    if(root -> data == ele)
        return true;

     return isPresent(root -> left, ele) or isPresent(root -> right, ele);
     
}

/*Iterative Approach*/

/*  The idea is simple insert the root node in the queue and check it that the data of it matches with key if yes return true
    else  keep on traversing all the node presnet in the queue until queue becomes empty
*/

bool searchElement(BinaryTree *root, int key){
    queue<BinaryTree*> q;
    q.push(root);
    while(q.size() > 0){
        BinaryTree *temp = q.front();
        q.pop();
        if(temp -> data == key)
            return true;
        if(temp -> left)
            q.push(temp -> left);
        if(temp -> right)
            q.push(temp -> right);
    
    }
    return false;
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

    if(searchElement(root, 15))
        cout << "Present";
     else
        cout << "False";

}