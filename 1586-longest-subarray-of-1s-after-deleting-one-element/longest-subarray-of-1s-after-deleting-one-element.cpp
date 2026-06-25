class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zerocount=0;
        int left=0;
        int right=0;
        int ans=0;

        while(right<nums.size()){
            if(nums[right]==0 ) zerocount++;

            while(zerocount>1){
               if(nums[left]==0) zerocount--;
               left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans-1;
    }
};