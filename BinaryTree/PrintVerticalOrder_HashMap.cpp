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
void printVerticalOrder(BinaryTree *root, int h, map<int, vector<int>> &map)
{
	if (root == NULL)
		return;
    
	map[h].push_back(root -> data);
	
	printVerticalOrder(root -> left, h - 1, map);
	printVerticalOrder(root -> right, h + 1, map);
	

}

void verticalOrder(BinaryTree *root)
{
	map<int, vector < int>> map;
    int h = 0;
	printVerticalOrder(root, h, map);
	
	 for(auto i = map.begin(); i != map.end(); ++i){
        for(int j = 0; j < i -> second.size(); ++j){
        cout << i -> first << "  " << i -> second[j] << " --> ";
        }
        cout << endl;
    }
}





int main()
{
	BinaryTree *root = nullptr;

	root = new BinaryTree(1);
	root->left = new BinaryTree(2);
	root->right = new BinaryTree(3);
	root->left->right = new BinaryTree(4);
	root->right->left = new BinaryTree(5);
	root->right->right = new BinaryTree(6);
	root->right->left->left = new BinaryTree(7);
	root->right->left->right = new BinaryTree(8);

		
    verticalOrder(root);

}