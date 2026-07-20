/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    string chec="";
    bool check(TreeNode* root,string s){
         if(root==NULL) {
            return s.contains(chec);
         }

         s=s+(char)root->val;
         bool left=check(root->left,s);
         bool right=check(root->right,s);

         return (left||right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        while(head!=NULL){
            chec=chec+(char)head->val;
            head=head->next;
        }
        return check(root,"");
    }
};