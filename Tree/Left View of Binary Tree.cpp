You are given the root of a binary tree. Your task is to return the left view of the binary tree.
The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.
If the tree is empty, return an empty list.


//solution 1 


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    void solve(Node* root,int currentlevel,int& maxlevel,vector<int>& ans){
        if(!root) return;
        if(currentlevel>maxlevel){
            ans.push_back(root->data);
            maxlevel= currentlevel;
        }
        solve(root->left,currentlevel+1,maxlevel,ans);
        solve(root->right,currentlevel+1,maxlevel,ans);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        int maxlevel=-1;
        solve(root,0,maxlevel,ans);
        return ans;
    }
};


//solution 2


class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int levelsize= q.size();
            for(int i=0; i<levelsize; i++){
                Node* curr= q.front();
                q.pop();
                if(i==0) ans.push_back(curr->data);
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }
        }
        return ans;
    }
};