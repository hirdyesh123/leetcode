class Solution {
public:
  
    int lengthOfLIS(vector<int>& nums) {
       vector<int>dp(nums.size(),1);
        int ans=0;
        for(int j=0;j<nums.size();j++){
            int i=0;
            int temp=dp[j];
            while(i<j){
                if(nums[i]<nums[j]) dp[j]=max(dp[j],temp+dp[i]);
                 i++;
            }
        }
       for(int i=0;i<dp.size();i++){
        ans=max(ans,dp[i]);
       }

       return ans;
    }
};