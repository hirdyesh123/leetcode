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
    bool find(TreeNode* root){
        if(root==NULL) return false;
        if(root->val==1) return true;
        bool left=find(root->left);
        bool right=find(root->right);

        return (left||right);
    }
       void  helper(TreeNode* root){
        if(root==NULL) return ;
        if(!find(root->left)) root->left=NULL;
        if(!find(root->right)) root->right=NULL;
 
        helper(root->left);
        helper(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root->val==0 && !find(root->left) && !find(root->right)) return NULL;
        helper(root);
        return root;
    }
};