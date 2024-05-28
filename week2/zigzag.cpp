/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void store(TreeNode*root,int i,vector<vector<int>>&ans,int level)
    {
        if(root==NULL)
        return;
        if(ans.size()<level+1)
        ans.push_back({});
        if(i<0)
        ans[level].push_back(root->val);
        else if(i>0)
        ans[level].insert(ans[level].begin(),root->val);
        store(root->right,-i,ans,level+1);
        store(root->left,-i,ans,level+1);
    } 
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        store(root,1,ans,0);
        return ans;
    }
};