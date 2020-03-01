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

/* This function return the level of the searched node in the given binary tree */
/* The idea behind to figure out the level of the given node is that 
    1. base condition if root is null return 0
    2. if root -> data == searchElement then return the level;
    3. traverse to the left subtree and increment level by 1;
       check if the levelOFTheTree is not zero then return the level
    4. traverse to the right subTree and increment level by 1
        and return the levelOfTheTree   

 */
int getLevelOfNode(BinaryTree *root, int searchElement, int level){
    if(root == NULL)
        return 0;

    if(root -> data == searchElement)
        return level;

    
    int levelOfTheTree = getLevelOfNode(root -> left, searchElement, level + 1);
    //cout << "Level of the Tree of Left:  " << root -> data << "  " << levelOfTheTree << endl;
    if(levelOfTheTree != 0)
        return levelOfTheTree;
    

    levelOfTheTree = getLevelOfNode(root -> right, searchElement, level + 1);    
    //cout << "Level of the Tree of Right: " << root -> data << "  " << levelOfTheTree << endl;
    return levelOfTheTree; 
      
    
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

    cout << getLevelOfNode(root, 9, 1);

}