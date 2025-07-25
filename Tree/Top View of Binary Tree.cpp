You are given a binary tree, and your task is to return its top view. The top view of a binary tree
 is the set of nodes visible when the tree is viewed from the top.

Note: 
Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree,
 consider the leftmost node only. 


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it= q.front();
            Node* node= it.first;
            int line= it.second;
            q.pop();
            if(mp.find(line)==mp.end()){
                mp[line]= node->data;
            }
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        for(auto it:mp){
          ans.push_back(it.second);
        }
        return ans;
    }
};