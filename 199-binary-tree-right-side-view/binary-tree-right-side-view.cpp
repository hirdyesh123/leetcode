class Solution {
public:
    int lvl(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(lvl(root->left),lvl(root->right));
    }
    void helper(TreeNode* root,int idx,int l,vector<int>&ans,vector<int>&index){
        if(root==NULL) return;
        
        if(index[l]<idx){
            ans[l]=root->val;
            index[l]=idx;
        }
        helper(root->left,2*idx-1,l+1,ans,index);
        helper(root->right,2*idx,l+1,ans,index);


    }
    vector<int> rightSideView(TreeNode* root) {
        int level=lvl(root);
        if(root==NULL) return{};
        vector<int>ans(level,0);
        vector<int>index(level,0);
        helper(root,1,0,ans,index);
        return ans;
    }
};