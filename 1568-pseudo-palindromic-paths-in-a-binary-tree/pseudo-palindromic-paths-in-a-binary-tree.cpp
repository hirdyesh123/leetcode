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
    bool checkpal(unordered_map<int,int>&map){
        int oddcheck=1;
        for(auto i:map){
            if(i.second%2==1) oddcheck--;
            if(oddcheck<0) return false;
        
        }

        return true;
    }
    void helper(TreeNode* root,unordered_map<int,int>&map){
        if(root==NULL) return ;
         map[root->val]++;
        if(root->left==NULL && root->right==NULL){
             if( checkpal(map)) ans++;
             map[root->val]--; 
             return;
        }
        helper(root->left,map);
        helper(root->right,map);
        map[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>map;
        for(int i=1;i<=9;i++){
            map[i]=0;
        }
        helper(root,map);

        return ans;
    }
};