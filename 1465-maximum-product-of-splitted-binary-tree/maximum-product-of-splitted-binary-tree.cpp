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
    int mod=1e9+7;
    long long ans=0;
    long long totalsum(TreeNode* root){
         if(root==NULL) return 0;
         return root->val+totalsum(root->left)+totalsum(root->right);
    }
    long long helper(TreeNode*root,int sum){
        if(root==NULL) return 0;
        
        long long left=helper(root->left,sum);
        long long right=helper(root->right,sum);

        long long currsum=root->val+left+right;
        ans=max(ans,(currsum*abs(sum-currsum)));
        return currsum;
    }
    int maxProduct(TreeNode* root) {
        long long sum=totalsum(root);
        
        helper(root,sum);
        return (ans%mod);
    }
};