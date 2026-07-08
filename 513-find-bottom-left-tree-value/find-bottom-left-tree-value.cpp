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
     bool check=false;
     int lvl(TreeNode*root){
        if(root==NULL) return 0;
       return 1+max(lvl(root->left),lvl(root->right));
     }

     void helper(TreeNode* root,int level,int lvlcheck){
           if(root==NULL) return;
           if(level==lvlcheck && check==false){
                check=true;
                ans=root->val;
                return;
           }
           helper(root->left,level,lvlcheck+1);
           helper(root->right,level,lvlcheck+1);
     }
    int findBottomLeftValue(TreeNode* root) {
        int level=lvl(root);
        helper(root,level,1);
        return ans;
    }
};