/* This problem can be easily solved with the help of Hashing. 
The idea is to create an empty map where each key represents the relative horizontal distance of the node from the root node and value in the map maintains a pair containing node’s value and its level number.
 Then we do a pre-order traversal of the tree and if current level of a node is less than maximum level seen so far for the same horizontal distance as current node’s or current horizontal distance is seen for the first time, 
 we update the value and the level for current horizontal distance in the map. For each node, we recur for its left subtree by decreasing horizontal distance and
 increasing level by 1 and recur for right subtree by increasing both level and horizontal distance by 1.*/


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
// The time complexity of above solution is O(nlog(n)) and auxiliary space used by the program is O(n).

 
void printTopView(BinaryTree *root, int dist, int level, map<int, pair<int, int>> &map){
    if(root == NULL)
        return;

    if(map.find(dist) == map.end() or level < map[dist].second){
        map[dist] = {root -> data , level};
    }
    printTopView(root -> left, dist - 1, level + 1, map);
    printTopView(root -> right, dist + 1, level + 1, map);


}

void topView(BinaryTree *root){

    if(root == NULL)
        return;

      // create an empty map where
     // key -> relative horizontal distance of the node from root node and
    // value -> pair containing node's value and its level    
    map<int, pair<int , int>> map;
    printTopView(root, 0, 1, map);

    for(auto i : map){
        cout << i.second.first << " ";
    }

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
    

    topView(root);
    

}