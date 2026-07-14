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
    int nodes(TreeNode* root){
        if(root==NULL) return 0;
        return 1+nodes(root->left)+nodes(root->right);
    }
    bool helper(TreeNode* root,int totalnodes,int idx){
        if(root==NULL) return true;
        if(idx>totalnodes) return false;
        bool left=helper(root->left,totalnodes,2*idx);
        bool right=helper(root->right,totalnodes,2*idx+1);
        return (left && right);
    }
    bool isCompleteTree(TreeNode* root) {
       int totalnodes=nodes(root);
       return helper(root,totalnodes,1);
    }
};