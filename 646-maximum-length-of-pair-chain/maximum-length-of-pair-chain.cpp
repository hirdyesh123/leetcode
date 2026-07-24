class Solution {
public:
    int helper(vector<vector<int>>&nums,int previdx,int idx,vector<vector<int>>&dp){
        if(idx>nums.size()-1) return 0;
        if(previdx!=-1 && dp[idx][previdx]!=-1) return dp[idx][previdx];
        int pick=0;
        if(previdx==-1 || nums[previdx][1]<nums[idx][0]) pick=1+helper(nums,idx,idx+1,dp);
        int notpick=helper(nums,previdx,idx+1,dp);
        if(previdx!=-1)return dp[idx][previdx]=max(pick,notpick);
        return max(pick,notpick);
    }
    int findLongestChain(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return helper(nums,-1,0,dp);
    }
};