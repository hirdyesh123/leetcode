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
    int  helper(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            if(root->val==1) return 1;
            else return 0;
        }
        int left=helper(root->left);
        int right=helper(root->right);
        if(left==0) root->left=NULL;
        if(right==0) root->right=NULL;
        return left+right+root->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        helper(root);
        if(root->val==0 && root->left==NULL && root->right==NULL) return NULL;
        return root;
    }
};