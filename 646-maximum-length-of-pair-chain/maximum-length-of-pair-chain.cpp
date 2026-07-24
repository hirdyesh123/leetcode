class Solution {
public:
    int findLongestChain(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(),
     [](vector<int>& a, vector<int>& b) {
         return a[1] < b[1];
     });
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int len=1;
            int temp=nums[i][1];
            for(int j=i+1;j<nums.size();j++){
               if(temp<nums[j][0]){
                 temp=nums[j][1];
                 len++;
               }
            }
            ans=max(len,ans);
        }
        return ans;
    }
};