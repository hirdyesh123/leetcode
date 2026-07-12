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
    bool helper(TreeNode* root,int target,int currsum){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL){
            currsum+=root->val;
            if(currsum==target) return true;
            else if(currsum<target) return false;
        }
       

        bool left=helper(root->left,target,currsum+root->val);
        bool right=helper(root->right,target,currsum+root->val);
        return (left||right);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum,0);
    }
};