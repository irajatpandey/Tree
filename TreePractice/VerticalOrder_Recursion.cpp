#include <bits/stdc++.h>
using namespace std;
class BinaryTree
{
public:
	int data;
	BinaryTree *left, *right;
	int height;
	BinaryTree(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
		height = 0;

	}
};

/*  Time Complexity of hashing based solution can be considered as O(n) under the assumption that we have good hashing function that allows insertion and retrieval operations in O(1) time.
    In the above C++ implementation, map of STL is used. map in STL is typically implemented using a Self-Balancing Binary Search Tree where all operations take O(Logn) time. 
    Therefore time complexity of the above implementation is O(nLogn). 
 
 */


void printVerticalOrder(BinaryTree *root, int dist,  map<int, vector<int>> &map){
    if(root == NULL)
        return;
    
    map[dist].push_back(root -> data);

     printVerticalOrder(root -> left, dist - 1,  map);
     printVerticalOrder(root -> right, dist + 1,  map);


}

void verticalOrder(BinaryTree *root){
      map<int, vector<int>> map;

      printVerticalOrder(root, 0, map);  


    for(auto itr : map){

        for(int j = 0 ; j <itr.second.size(); j++)
            cout << itr.second[j] << " ";
    }
}



int main()
{
	BinaryTree *root = nullptr;

	// root = new BinaryTree(1);
	// root->left = new BinaryTree(2);
	// root->right = new BinaryTree(3);
	// root->left->right = new BinaryTree(4);
	// root->right->left = new BinaryTree(5);
	// root->right->right = new BinaryTree(6);
	// root->right->left->left = new BinaryTree(7);
	// root->right->left->right = new BinaryTree(8);

    root = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->right->left = new BinaryTree(4);


    verticalOrder(root);

}