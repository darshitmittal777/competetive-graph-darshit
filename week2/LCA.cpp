/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find_path(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == NULL) return false;
        path.push_back(root);
        if (root == target) return true;
        
        if (find_path(root->left, target, path) || find_path(root->right, target, path)) {
            return true;
        }
        
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path ; find_path(root,p,p_path);
        vector<TreeNode*> q_path ; find_path(root,q,q_path);
        TreeNode* ans=root;
        int i = 0;
        while (i < p_path.size() && i < q_path.size() && p_path[i] == q_path[i]) {
            i++;
        }
        
        return p_path[i - 1];
    }
};