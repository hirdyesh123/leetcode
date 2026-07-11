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
    int level(TreeNode*root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    bool check(TreeNode* root,int lvl,int lvlcheck){
        if(root==NULL) return false;
        if(lvl==lvlcheck) return true;
        bool left=check(root->left,lvl,lvlcheck+1);
        bool right=check(root->right,lvl,lvlcheck+1);
       
        return (left || right);
    }
   TreeNode* helper(TreeNode* root,int lvl,int lvlcheck){
      if(root==NULL) return NULL;
       if(lvlcheck==lvl)
        return root;
      if(check(root->left,lvl,lvlcheck+1) && check(root->right,lvl,lvlcheck+1)) return root;
      else if(check(root->left,lvl,lvlcheck+1)) return helper(root->left,lvl,lvlcheck+1);

      return helper(root->right,lvl,lvlcheck+1);
   }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int lvl=level(root);
        return  helper(root,lvl,1);
    }
};