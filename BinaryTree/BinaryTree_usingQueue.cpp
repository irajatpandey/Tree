#include <bits/stdc++.h>
using namespace std;
class Node{
    public:

    Node *leftChild;
    Node *rightChild;
    int data;

    Node(int x){

        leftChild = NULL;
        rightChild = NULL;
        data = x;   
    }



};


void printTreeProper(Node* root)
{

    if(root == NULL) 
        return;

    cout << root -> data << " :";

    if(root -> leftChild)
        cout << "L" << root -> leftChild -> data << " ";

    if(root -> rightChild)
        cout << "R" << root -> rightChild -> data;

    
    cout << endl;

    printTreeProper(root -> leftChild);
    printTreeProper(root -> rightChild);
    return;


}

void preorder(Node *root){
    if(root){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
        cout << root -> data << " ";
        preorder(root ->leftChild);
        preorder(root -> rightChild);

    }
    
}

void inorder(Node *root){
    if(root){
        inorder(root -> leftChild);
        cout << root -> data << " ";
        inorder(root -> rightChild);
    }
   
}

void postorder(Node *root){
    if(root){
        postorder(root -> leftChild);
        postorder(root -> rightChild);
        cout << root -> data << " ";
    }
}


int main(){

    queue<Node *> q;
    cout << "Enter the root value" << endl;
    
    int x;
    cin >> x; 

    Node *root = new Node(x);
    q.push(root);

    while(q.empty() != true){

        Node *temp = q.front();
        q.pop();
        cout << "Enter the left child of " << temp -> data << endl;
        int val;
        cin >> val;

        if(val != -1){

            Node *newNode = new Node(val);
            temp -> leftChild = newNode;
            q.push(newNode);
        }

        cout << "Enter the value of the right child of " << temp -> data << endl;
        cin  >>  val;

        if(val != -1){
            Node *newNode = new Node(val);
            temp -> rightChild = newNode;
            q.push(newNode);
        }
    }

    preorder(root);
    
    cout << endl;

    inorder(root);

    cout << endl;

    postorder(root);

    cout << endl << endl;

    printTreeProper(root);

    return 0;
}