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
    int count=0;
    vector<int>solve(TreeNode* root,int distance){
        if(root==NULL) return {};
        if(root->left==NULL && root->right==NULL){
            return{1};
        }
        vector<int>left= solve(root->left,distance);
        vector<int>right=solve(root->right,distance);
        for(int i=0;i<left.size();i++){
            for(int j=0;j<right.size();j++){
                if(left[i]+right[j]<=distance) count++;
            }
        }
        left.insert(left.end(),right.begin(),right.end());
        for(auto &x:left) x++;
        
        return left;

    }
    int countPairs(TreeNode* root, int distance) {
        solve(root,distance);
        return count;
    }
};