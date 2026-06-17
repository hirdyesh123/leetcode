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
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        temp=head;
        unordered_map<int,int>m;
        int i=0;
        int maxi=INT_MIN;
        while(temp!=NULL){
            if(size/2 > i){
                m[i]=temp->val;
            }
            else {
                int i2= size-i-1;
                m[i2]+=temp->val;
                maxi=max(maxi,m[i2]);
            }
            i++;
            temp=temp->next;
        }
        return maxi;
    }
};