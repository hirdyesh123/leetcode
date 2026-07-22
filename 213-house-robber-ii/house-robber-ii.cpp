class Solution {
public:
      int helper(int i,vector<int>&dp,int n,vector<int>&nums){
         if(i>n) return 0;
         if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+helper(i+2,dp,n,nums);
        int notpick=helper(i+1,dp,n,nums);

         return dp[i]=max(pick,notpick);  
    }
    int rob(vector<int>& nums) {
           int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp(nums.size(),-1);
        vector<int>dp1(nums.size(),-1);
     
       int a= helper(0,dp,n-2,nums);
       int b=helper(1,dp1,n-1,nums);
       return max(a,b);
    }
};