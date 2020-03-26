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


/*We can print spiral order traversal in O(n) time and O(n) extra space. The idea is to use two stacks. 
We can use one stack for printing from left to right and other stack for printing from right to left. 
In every iteration, we have nodes of one level in one of the stacks. We print the nodes, and push nodes of next level in other stack.
*/


void spiral(BinaryTree *root){
	if(root == NULL) return;
	stack<BinaryTree *> st1;
	stack<BinaryTree *> st2;

	st1.push(root);

	while(!st1.empty() or !st2.empty()){

		while(!st1.empty()){
			BinaryTree *temp = st1.top();
			st1.pop();

			cout << temp -> data << " ";

			if(temp -> right)
				st2.push(temp -> right);
			if(temp -> left)
				st2.push(temp -> left);
		}

		while(!st2.empty()){
			BinaryTree *temp = st2.top(); st2.pop();

			cout << temp -> data << " ";

			if(temp -> left)
				st1.push(temp -> left);
			if(temp -> right)
				st1.push(temp -> right);
		}
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