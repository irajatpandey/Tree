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

  // Recursive function to do a pre-order traversal of the tree and fill the map
 // Here node has 'dist' horizontal distance from the root of the
// tree and level represent level of the node

void printBottomView(BinaryTree *root, int dist, int level, map<int, pair<int, int>> &map){
    if(root == NULL)
        return;

    
      // if current level is more than or equal to maximum level seen so far
     // for the same horizontal distance or horizontal distance is seen for 
    // the first time, update the map

    if(level >= map[dist].second)
        map[dist] = {root -> data, level};

    printBottomView(root -> left, dist - 1, level + 1, map);
    printBottomView(root -> right, dist + 1, level + 1, map);    




}
void bottomView(BinaryTree *root){
    if(root == NULL)
       return;


     // create an empty map where
    // key -> relative horizontal distance of the node from root node and
   // value -> pair containing node's value and its level

   
    map<int, pair<int, int>> map;
    printBottomView(root, 0, 1, map);

    for(auto itr : map)
        cout << itr.second.first << " ";
}


int main(){


      /* Construct below tree
          1
        /   \
       /     \
      2       3
            /   \
           /     \
          5       6
        /   \
       /     \
      7       8
            /   \
           /     \
          9      10
    */
   

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

    bottomView(root);

}