class Solution {
public:
    long long helper(vector<int>&nums,int idx,vector<vector<long long>>&dp,bool pos){
        if(idx>nums.size()-1) return 0;
        if(dp[idx][pos]!=-1) return dp[idx][pos];

        long long notpick=helper(nums,idx+1,dp,pos);
        long long val=nums[idx];
        if(pos==false) val=-val;
        long long pick=val+helper(nums,idx+1,dp,!pos);
        return dp[idx][pos]= max(pick,notpick);

    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return helper(nums,0,dp,true);
    }
};