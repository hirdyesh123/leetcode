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
    int ans=0;
    void helper(TreeNode* root,int maxanc){
        if(root==NULL) return;
        ans=max(ans,abs(root->val-maxanc));
        helper(root->left,max(root->val,maxanc));
        helper(root->right,max(root->val,maxanc));
    }
    void helper2(TreeNode* root,int minanc){
        if(root==NULL) return;
        ans=max(ans,abs(root->val-minanc));
        helper2(root->left,min(root->val,minanc));
        helper2(root->right,min(root->val,minanc));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root->left,root->val);
        helper(root->right,root->val);
        helper2(root->left,root->val);
        helper2(root->right,root->val);
        return ans;
    }
};