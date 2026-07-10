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
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL) return true;
        int level=0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            int prev=q.front()->val;
            int counter=0;
            for(int i=1;i<=size;i++){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);

                if(level%2==0){
                    if(prev>=temp->val && counter!=0) return false;
                    if(temp->val%2==0) return false;
                    if(temp->val%2)
                    prev=temp->val;
                    counter++;
                }
                else {
                    if(prev<=temp->val && counter!=0) return false;
                    if(temp->val%2!=0) return false;
                    prev=temp->val;
                    counter++;
                }
            }
            level++;
        }

        return true;
    }
};