Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

//Recursive 

class Solution {
public:
    bool isMirror(TreeNode* p, TreeNode* q){
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr || p->val != q->val) return false;

        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;
        return isMirror(root->left, root->right);
    }
};



//Iterative 

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       queue<pair<TreeNode*, TreeNode*>> q;
       q.push({root->left, root->right});
       while(!q.empty()){
        pair<TreeNode*, TreeNode*> current= q.front();
        q.pop();
        TreeNode* l= current.first;
        TreeNode* r= current.second;
        if(l==nullptr && r==nullptr) continue;
        if(l==nullptr || r==nullptr || l->val != r->val) return false;
        q.push({l->left, r->right});
        q.push({l->right, r->left});
       }
       return true;
    }
};




 