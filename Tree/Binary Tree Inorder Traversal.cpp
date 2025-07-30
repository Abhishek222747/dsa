Given the root of a binary tree, return the inorder traversal of its nodes' values.


//Solution 1: Recursive Solution

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       if(root==nullptr) return ans;
       inorder(root,ans);
       return ans;
    }
    void inorder(TreeNode* root, vector<int>& ans){
        if(root== nullptr) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
};


//Solution 2: Iterative Solution

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       TreeNode* curr= root;
       stack<TreeNode*> st;

       while(curr!=nullptr|| !st.empty()){

          //go as far as left
          while(curr!=nullptr){
            st.push(curr);
            curr= curr->left;
          }

          //now pop from stack and process
          curr= st.top(); st.pop();
          ans.push_back(curr->val);

          //visit the right
          curr= curr->right;
       }
       return ans;
    }
    
};