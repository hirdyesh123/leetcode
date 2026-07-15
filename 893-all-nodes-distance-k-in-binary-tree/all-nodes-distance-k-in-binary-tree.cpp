/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:  
    void helper(TreeNode* root,vector<int>graph[]){
        if(root==NULL) return ;
        if(root->left!=NULL){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right!=NULL){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        helper(root->left,graph);
        helper(root->right,graph);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root->left==NULL && root->right==NULL) return {};

        vector<int>graph[501];
        vector<int>isvisited(501,0);
        queue<pair<int,int>>q;
        vector<int>ans;
        helper(root,graph);
        q.push({target->val,0});
        isvisited[target->val]=1;
        while(!q.empty()){
           auto top= q.front();
           q.pop();
           if(top.second==k) ans.push_back(top.first);
           for(auto i:graph[top.first]){
            if(isvisited[i]!=1){
                isvisited[i]=1;
                q.push({i,top.second+1});
            }
           }
        }

        return ans;
    }
};