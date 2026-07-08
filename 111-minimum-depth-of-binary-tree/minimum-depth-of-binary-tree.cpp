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
    int minlength=INT_MAX;
    void helper(TreeNode* root,int length){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
             minlength=min(minlength,length);
             return;
        }
        helper(root->left,length+1);
        helper(root->right,length+1);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root,1);

        return minlength;
    }
};