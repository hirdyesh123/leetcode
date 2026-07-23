class Solution {
public:
    int helper(vector<int>&nums,vector<vector<int>>&dp,int previdx,int idx){
        if(idx>nums.size()-1) return 0;
         
        if(previdx!=-1 && dp[idx][previdx]!=-1) return dp[idx][previdx];
        int pick=0;
        if(previdx==-1 || nums[idx]>nums[previdx]) pick=1+helper(nums,dp,idx,idx+1);
        int notpick=helper(nums,dp,previdx,idx+1);
         if(previdx!=-1) return dp[idx][previdx]= max(pick,notpick);
        return max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return helper(nums,dp,-1,0);
    }
};