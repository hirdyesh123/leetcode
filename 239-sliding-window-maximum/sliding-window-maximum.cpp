class Solution {
public:
    void helper(deque<int>&dq,int idx,vector<int>&nums){
        while(!dq.empty() && nums[idx]>nums[dq.back()]) dq.pop_back();
        dq.push_back(idx);
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        deque<int>dq;
        vector<int>ans;
        while(right<nums.size()){
            helper(dq,right,nums);
           
            while(right-left+1==k){
               ans.push_back(nums[dq.front()]);
               if(nums[dq.front()]==nums[left]) dq.pop_front();
               left++;
            }

            right++;
        }

        return ans;
    }
};