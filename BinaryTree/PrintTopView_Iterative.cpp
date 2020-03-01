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

void printTop(BinaryTree *root){
    if(root == NULL)
        return;
    
    queue<BinaryTree *> q;
    q.push(root);
    
    map<int, int> map;
    while(q.size() > 0){
        BinaryTree *temp = q.front();
        int h = temp -> height;
        q.pop();
        if(map.find(h) == map.end()){
            map.insert({h, temp -> data});
        }
        
        if(temp -> left){
            temp -> left -> height = h - 1;
            q.push(temp -> left);
        }

        if(temp -> right){
            temp -> right -> height = h + 1;
            q.push(temp -> right);
        }

    }
     for(auto i = map.begin(); i != map.end(); ++i)
        cout <<i -> first << "  " << i -> second << endl;

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
    

    printTop(root);
    

}