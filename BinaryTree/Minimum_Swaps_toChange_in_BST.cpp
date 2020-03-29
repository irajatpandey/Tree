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
void inorder(BinaryTree * root, vector<int> &v){

    if(!root) return;

    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);

}

int minimumSwap(vector<int> v){
    
    vector<pair<int, int>> pairArray(v.size());

    for(int i = 0; i < v.size(); i++){
        pairArray[i].first = v[i];
        pairArray[i].second = i;

    }
    sort(pairArray.begin(), pairArray.end());
    int answer = 0;

    for(int i = 0; i < v.size(); i++){
    if(pairArray[i].second == i)
            continue;

        else{
       
            swap(pairArray[i].first, pairArray[pairArray[i].second].first);
            swap(pairArray[i].second, pairArray[pairArray[i].second].second);

        }
        if(i != pairArray[i].second)
            i--;
        answer++;
        
    }
    return answer;
}

// Time Complexity is O(nlogn)
// Space Complexity is O(n)
int swapCountToChangeInBST(BinaryTree *root){
    if(!root) return 0;
    vector<int> v;
    inorder(root, v);

    return minimumSwap(v);  

}



int main(){

    BinaryTree *root = new BinaryTree(12); 
    root->left = new BinaryTree(5); 
    root->left->left = new BinaryTree(3); 
    root->left->right = new BinaryTree(9); 
    root->left->left->left = new BinaryTree(1); 
    root->left->right->left = new BinaryTree(1); 
    
    cout <<"Minimum Swap required to converet BinaryTree into BST is " << swapCountToChangeInBST(root);



}