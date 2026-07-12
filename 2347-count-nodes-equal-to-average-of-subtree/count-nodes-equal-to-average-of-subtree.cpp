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
    int counter=0;
    pair<int,int> helper(TreeNode* root){
        if(root==NULL){
            return {0,0};  //number of nodes,sum
        }
       if(root->left==NULL && root->right==NULL){
           counter++;
          return {1,root->val};
       }
        auto left=helper(root->left);
        auto right=helper(root->right);
        int totalsum=left.second+right.second+root->val;
        int totalnodes=left.first+right.first+1;
        if((totalsum/totalnodes)==root->val) counter++;
        return {totalnodes,totalsum};
    }
    int averageOfSubtree(TreeNode* root) {
        auto temp=helper(root);

        return counter;
    }
};