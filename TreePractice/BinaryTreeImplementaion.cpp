#include<iostream>
#include<queue>
using namespace std;
class BinaryTree{

    public:
    int data;
    BinaryTree *left, *right;

    BinaryTree(int x){
        data = x;
        left = right = NULL;
    }
};


void preorder(BinaryTree *root){
    if(root){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
        cout << root -> data << " ";
        preorder(root ->left);
        preorder(root -> right);

    }
    
}


int main(){

    queue<BinaryTree *> q;
    int x;
    cout << "Enter the value of the root node" << endl;
    cin >> x;

    BinaryTree *root = new BinaryTree(x);
    q.push(root);

    while (!q.empty()){
        BinaryTree *temp = q.front();
        q.pop();
        cout << "Enter the left child of " << temp -> data << endl; 
        int val;
        cin >> val;
        if(val != -1){
            BinaryTree *newNode = new BinaryTree(val);
            temp -> left = newNode;
            q.push(newNode);
        }

        cout << "Enter the value of the right child of " << temp -> data << endl;
        cin  >>  val;

        if(val != -1){
            BinaryTree *newNode = new BinaryTree(val);
            temp -> right = newNode;
            q.push(newNode);
        }


    }
    
    preorder(root);

    return 0;
}