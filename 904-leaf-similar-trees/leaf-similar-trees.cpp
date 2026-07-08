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
    void helper(TreeNode* root,vector<int>&nums){
         if(root==NULL) return;
         if(root->left==NULL && root->right==NULL){
            nums.push_back(root->val);
            return;
         }
         helper(root->left,nums);
         helper(root->right,nums);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>check1;
        vector<int>check2;
        helper(root1,check1);
        helper(root2,check2);
        return (check1==check2);
    }
};