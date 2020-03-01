
#include <bits/stdc++.h>
using namespace std;
class BST{
    public:

    BST *left;
    BST *right;
    int data;
    int height;

    BST(int x){

        left = NULL;
        right = NULL;
        height = 1;
        data = x;   
    }

};

int calculateHeight(BST *root){
    return (root == NULL ? 0 : root -> height); 
}

int balanceFactor(BST *root){
     if(root == NULL)
            return 0;
        else
            return calculateHeight(root -> left) - calculateHeight(root -> right);

}

BST *rl_Rotation(BST *root){
    return root;
}


BST *lr_Rotation(BST *root){
    return root;
}


BST *rr_Rotation(BST *root){
    return root;
}

BST *ll_Rotation(BST *root){
     BST *pl = root -> right;
     BST *plr = pl -> left;

     pl -> left = root;
     root -> right = plr;

     root -> height =  max(calculateHeight(root -> left), calculateHeight(root -> right)) + 1;
     pl -> height =  max(calculateHeight(pl -> left), calculateHeight(pl -> right)) + 1;

    return pl;


}



BST *insertion(BST *root, int key){
     if(root == NULL){
         return new BST(key);
     }    
     if(key < root -> data){
         root -> left = insertion(root -> left, key);
     }
     else if(key > root -> data)
        root -> right = insertion(root -> right, key);
        root -> height = max(calculateHeight(root -> left), calculateHeight(root -> right)) + 1;

        if(balanceFactor(root) == 2 and balanceFactor(root -> left) == 1){
            
            return ll_Rotation(root);
        }

        // else if(balanceFactor(root) == 2 and balanceFactor(root -> left) == -1){
        //     return lr_Rotation(root);
        // }
        // else if(balanceFactor(root) == -2 and balanceFactor(root -> left) == -1){
        //     return rr_Rotation(root);
        // }
        // else if(balanceFactor(root) == -2 and balanceFactor(root -> left) == 1){
        //     return rl_Rotation(root);
        // } 
     return root;   

}

void printTree(BST* root)
{

    if(root == NULL) 
        return;

    cout << root -> data << " :";

    if(root -> left)
        cout << "L " << root -> left -> data << " ";

    if(root -> right)
        cout << "R " << root -> right -> data;

    
    cout << endl;

    printTree(root -> left);
    printTree(root -> right);
    return;


}

int main(){

    BST *root = NULL;
    root = insertion(root , 10);
    insertion(root, 5);
    insertion(root , 2);
    
    printTree(root);
    return 0;
}