class Solution {
public:

   bool check(string s2,string s1){
         if(!(s2.size()-1==s1.size())) return false;

         int i=0;
         int j=0;
         while(j<s2.size()){
            if(i<s1.size() && s1[i]==s2[j]) i++;

            j++;
         }
         if(i>=s1.size()) return true;
         return false;
   }
  
    int longestStrChain(vector<string>& nums) {
        sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
        });
        vector<int>dp(nums.size(),1);
        
        for(int j=0;j<nums.size();j++){
           int i=0;
           int temp=dp[i];
           while(i<j){
             if(check(nums[j],nums[i])) dp[j]=max(dp[j],temp+dp[i]);
             i++;
           }
        }
        int ans=0;
        for(int i=0;i<dp.size();i++){
           ans=max(ans,dp[i]);
        }
        return ans;
    }
};