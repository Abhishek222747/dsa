Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBSTUtil(Node* root, int min, int max){
        if(!root) return true;
        
        if(root->data<min || root->data>max) return false;
        
        return isBSTUtil(root->left,min,root->data-1) &&
        isBSTUtil(root->right,root->data+1,max);
    }
    bool isBST(Node* root) {
        // Your code here
        return isBSTUtil(root, INT_MIN,INT_MAX);
    }
};