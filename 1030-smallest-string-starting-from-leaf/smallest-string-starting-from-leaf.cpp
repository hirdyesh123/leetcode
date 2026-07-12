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
    string mini="";
    void helper(TreeNode* root,string s){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            s=char(root->val+97)+s;
            if(mini=="") mini=s;
            else mini=min(mini,s);
            return;
        }
        s=char(root->val+97)+s;
        helper(root->left,s);
        helper(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        helper(root,"");


        return  mini;
    }
};