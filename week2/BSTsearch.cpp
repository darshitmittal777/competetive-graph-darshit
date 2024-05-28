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
    void find(TreeNode* root, int val,TreeNode* &ans)
    {
        if(root==NULL)
        return;
        if(val>root->val)
        find(root->right,val,ans);
        else if(val<root->val)
        find(root->left,val,ans);
        else if(val==root->val)
        {
            ans = root;
            return;
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans=NULL;
        find(root,val,ans);
        return(ans);
    }
};