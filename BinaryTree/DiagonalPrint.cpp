#include <bits/stdc++.h>
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


void printVerticalView(BinaryTree *root, int dist, map<int, vector<int>> &map){

	if(root == NULL)
		return;
	map[dist].push_back(root -> data);

	printVerticalView(root -> left, dist - 1, map);
	printVerticalView(root -> right, dist + 1, map);


}


void diagonalPrint(BinaryTree *root, int dist, map<int, vector<int>> &map){
	 if(root == NULL)
	 	return;
	 map[dist].push_back(root -> data);

	 //if(root -> left)
	 	diagonalPrint(root -> left, dist + 1, map);
	// if(root -> right)
	 	diagonalPrint(root -> right, dist, map);



}


void diagonal(BinaryTree *root){
	if(root == NULL) return;

	map<int, vector<int>> map;

	diagonalPrint(root, 0, map);

	for(auto i : map){
		for(auto j = 0; j < i.second.size(); j++)
			cout << i.second[j] << " ";
		cout << endl;
	}

	
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
    */

	    BinaryTree* root = new BinaryTree(1);
	    root -> left = new BinaryTree(2);
	    root -> right = new BinaryTree(3);
	    root -> right -> left = new BinaryTree(5);
	    root -> right -> right = new BinaryTree(6);
	    root -> right -> left -> left = new BinaryTree(7);
	    root -> right -> left -> right = new BinaryTree(8);

	    diagonal(root);


	return 0;    
}