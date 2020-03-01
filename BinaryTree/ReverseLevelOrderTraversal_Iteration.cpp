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

/* Iterative Approach to print Reverse Level Order */

/* Time Complexity:
   First operation and second operation both take the time of order O(N) and also the operations are not nested. 
   Hence the time complexity will be  O(N) + O(N) = O(2N) = O(N).
   
   Space Complexity:
   We need auxiliary space for a queue and stack. Both engage space of order O(N). 
   A queue has to keep the track of nodes of a whole level and the last level of a balanced binary tree has O(N/2) elements,
   which is of order O(N). Hence the space complexity is O(N) + O(N) = O(N).


*/

void printReverseLevelOrderTraversal(BinaryTree *root){
    if(root == NULL)
        return;
    queue<BinaryTree*> q;
    stack<BinaryTree*> myStack;

    q.push(root);
    while(q.size()){
        BinaryTree *temp = q.front();
        if(temp -> right)
            q.push(temp -> right);
        if(temp -> left)
            q.push(temp -> left);

        q.pop();
        myStack.push(temp);        


    }  
    while(myStack.size()){
        cout << myStack.top() -> data << " ";
        myStack.pop();

    }

}


int main(){

    BinaryTree *root =      new BinaryTree(10); 
    root -> left    =       new BinaryTree(8); 
    root -> right      =    new BinaryTree(2); 
    root -> left -> left  = new BinaryTree(3); 
    root -> left -> right = new BinaryTree(5); 
    root -> right -> left = new BinaryTree(2); 
   
    printReverseLevelOrderTraversal(root);



}