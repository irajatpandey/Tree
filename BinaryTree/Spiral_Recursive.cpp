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


/*This problem can be seen as an extension of the level order traversal post.
To print the nodes in spiral order, nodes at different levels should be printed in alternating order. 
An additional Boolean variable flag is used to change printing order of levels. 
If flag is 1 then printGivenLevel() prints nodes from left to right else from right to left. 
Value of flag is flipped in each iteration to change the order.*/





int height(BinaryTree *root){

    if(root == NULL)
        return 0;

     return max(height(root -> left), height(root -> right)) + 1;   
}

void printSpiral(BinaryTree *root, int level, bool flag){

    if(root == NULL) return;
	if(level == 1)
	 	cout << root -> data << " ";

	else if(level > 1){

		if(flag == true){
	
		 printSpiral(root -> left, level - 1, flag);
		 printSpiral(root -> right, level - 1, flag);
	}

	else{
		
	 printSpiral(root -> right, level - 1, flag);
	 printSpiral(root -> left, level - 1, flag);

	}
}

}

void spiral(BinaryTree *root){
	
	if(root == NULL) return;
	bool flag = false;
	int h = height(root);

	for(int i = 1; i <= h; i++){
		printSpiral(root, i, flag);
		flag = !flag;
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

	    cout << "Spiral Order traversal of binary tree is \n";
	    spiral(root);


	return 0;    
}