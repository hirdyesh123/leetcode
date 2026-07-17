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
    TreeNode* start=NULL;
    int maxi=INT_MIN;
    void helper(TreeNode* root,int s,unordered_map<TreeNode*,TreeNode*>&map){
        if(root==NULL) return;
        if(root->val==s) start=root;
        maxi=max(maxi,root->val);
        if(root->left!=NULL) map[root->left]=root;
        if(root->right!=NULL) map[root->right]=root;
        helper(root->left,s,map);
        helper(root->right,s,map);
    }
    int amountOfTime(TreeNode* root, int s) {
        int ans=0;
        unordered_map<TreeNode*,TreeNode*>map;
        helper(root,s,map);
        vector<int>isvisited(maxi+1,0);
        queue<pair<TreeNode*,int>>q;
        q.push({start,0});
        isvisited[s]=1;

        while(!q.empty()){
            auto top=q.front();
            q.pop();
            TreeNode* node=top.first;
            int dist=top.second;
            ans=max(ans,dist);
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