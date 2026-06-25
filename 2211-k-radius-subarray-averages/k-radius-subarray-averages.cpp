class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        vector<long long >suffix(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        int left=0;
        int right=0;
        long long sum=0;
        while(right<n-k){
            sum+=nums[right];
            if(right-left<k) ans.push_back(-1);
           else if(right-left==k){
                long long totalsum= sum+suffix[right+1]-suffix[right+k+1];
                 int avg= totalsum/(2*k+1);
                 ans.push_back(avg);
                 sum-=nums[left];
                 left++;
            }
            right++;
        }
        for(int i=right;i<n;i++){
            ans.push_back(-1);
        }
        return ans;
    }
};