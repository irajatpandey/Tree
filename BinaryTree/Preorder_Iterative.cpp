#include<iostream>
#include<stack>
using namespace std;
class BinaryTree{
    public:
    int data;
    BinaryTree  *leftChild, *rightChild;

    BinaryTree(int x){
        data = x;
        leftChild = NULL;
        rightChild = NULL;
    }
    
};


void preorderTraversal(BinaryTree *root){
    stack<BinaryTree *> myStack;
    
    while(root != NULL or !myStack.empty()){
        if(root){
        cout << root -> data << " ";                                                 
        myStack.push(root);
        root = root -> leftChild;
         
    }
    else{
        root = myStack.top();
        myStack.pop();
        root = root -> rightChild;
    }

    }
    cout << endl;
}

void inorder(BinaryTree *root){
    if(root == NULL)
        return;

        
    stack<BinaryTree*> myStack;
    while(root != NULL or !myStack.empty()){
        if(root != NULL){
            myStack.push(root);
            root = root -> leftChild;
            
        }
        else{
            root = myStack.top();
            cout << root -> data << " ";
            myStack.pop();
            root = root -> rightChild;
           
        }
    }

}


void postorderTraversal(BinaryTree *root){
    if(root == NULL)
        return;
    stack<BinaryTree *> myStack;
    while(root != NULL or !myStack.empty()){
        if(root){
            myStack.push(root);
            root = root -> leftChild;
        }

        else{
            root = myStack.top();
            cout << root -> data << " ";
            
            if(root -> rightChild){
            root = root -> rightChild;
            myStack.push(root);
          }
            
            myStack.pop();

        }
        
    }
    
      


}
int main(){
  BinaryTree *root = new BinaryTree(10); 
  root -> leftChild  = new  BinaryTree(8); 
  root -> rightChild       = new BinaryTree(2); 
  root -> leftChild -> leftChild  = new BinaryTree(3); 
  root -> leftChild -> rightChild = new BinaryTree(5); 
  root -> rightChild -> leftChild = new BinaryTree(2); 
  preorderTraversal(root); 
  postorderTraversal(root);
  inorder(root);



}
