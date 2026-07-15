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
    void helper(TreeNode* root,int maxanc,int minanc){
        if(root==NULL) return;
        ans=max(ans,abs(root->val-maxanc));
        ans=max(ans,abs(root->val-minanc));
        helper(root->left,max(root->val,maxanc),min(root->val,minanc));
        helper(root->right,max(root->val,maxanc),min(root->val,minanc));
    }
   
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root->left,root->val,root->val);
        helper(root->right,root->val,root->val);
    
        return ans;
    }
};