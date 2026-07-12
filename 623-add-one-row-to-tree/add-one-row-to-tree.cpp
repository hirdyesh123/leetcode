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
    void helper(TreeNode* root,int currdepth,int depth,int val){
        if(root==NULL) return ;
        if(currdepth==depth-1){
            TreeNode* temp1=root->left;
            TreeNode* temp2=root->right;
            TreeNode* dummy1=new TreeNode(val);
            TreeNode* dummy2=new TreeNode(val);
            root->left=dummy1;
            root->right=dummy2;
            dummy1->left=temp1;
            dummy2->right=temp2;
            return;
        }
        helper(root->left,currdepth+1,depth,val);
        helper(root->right,currdepth+1,depth,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if(depth==1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        helper(root,1,depth,val);
        return root;
    }
};