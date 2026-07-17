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
    void helper(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&map){
        if(root==NULL) return;

        if(root->left!=NULL) map[root->left]=root;
        if(root->right!=NULL) map[root->right]=root;

        helper(root->left,map);
        helper(root->right,map);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         vector<int>ans;
         unordered_map<TreeNode*,TreeNode*>map;
         vector<int>isvisited(501,0);
         queue<pair<TreeNode*,int>>q;
         q.push({target,0});
         isvisited[target->val]=1;
         helper(root,map);
         while(!q.empty()){
            auto top=q.front();
            q.pop();
            TreeNode* node=top.first;
            int dist=top.second;
            if(dist==k) ans.push_back(node->val);
            if(node->left!=NULL && !isvisited[node->left->val]){
                isvisited[node->left->val]=1;
                q.push({node->left,dist+1});
            }
            if(node->right!=NULL && !isvisited[node->right->val]){
                isvisited[node->right->val]=1;
                q.push({node->right,dist+1});
            }
             
            if(map.count(node)!=0 && !isvisited[map[node]->val]){
                isvisited[map[node]->val]=1;
                q.push({map[node],dist+1});
            }
         }
        return ans;
    } 
};