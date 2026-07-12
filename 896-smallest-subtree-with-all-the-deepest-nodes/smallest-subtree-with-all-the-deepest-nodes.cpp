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
    
    pair<int,TreeNode*> helper(TreeNode* root){
        if(root==NULL) return {0,NULL};
        if(root->left==NULL && root->right==NULL){
            return {1,root};
        }
        auto left=helper(root->left);
        auto right=helper(root->right);
        if(left.first==right.first) return {left.first+1,root};
        else if(left.first>right.first) return {left.first+1,left.second};
        return {right.first+1,right.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
          return helper(root).second;
    }
};