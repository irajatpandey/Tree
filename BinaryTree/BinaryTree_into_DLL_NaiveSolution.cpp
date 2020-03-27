#include <bits/stdc++.h>
using namespace std;
class DLL{

public:
    int data;
    DLL *next;
    DLL *prev;
 
    DLL(int x){
        data = x;
        next = prev  = NULL;
    }
};




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

 DLL* insert(vector<int> v){
    static DLL *head = NULL;

    for(auto i : v){
     DLL *newNode = new DLL(i);

     if(head == NULL){
        head = newNode;
     }
     else{
        DLL *temp = head;
        while(temp -> next != NULL)
             temp = temp -> next;

         temp -> next = newNode;
         newNode -> prev = temp;
       
     }
     }
     return head;
}


void inorder(BinaryTree *root, vector<int> &v){
   
    if(root == NULL) return;

    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);

    
}

void printList(DLL *head){
    if(!head) return;

    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}



void convertBinaryTreeIntoDLL(BinaryTree *root){
     if(!root) return;
     vector<int> v;

      inorder(root, v);
      DLL *head = insert(v);
      printList(head);
      
     


}




int main(){

   
    BinaryTree *root  = new BinaryTree(10); 
    root->left        = new BinaryTree(12); 
    root->right       = new BinaryTree(15); 
    root->left->left  = new BinaryTree(25); 
    root->left->right = new BinaryTree(30); 
    root->right->left = new BinaryTree(36); 
   
    

    convertBinaryTreeIntoDLL(root);
   


}