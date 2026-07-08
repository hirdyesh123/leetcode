class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum=0;
        int sum=0;
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxsum=max(maxsum,sum);
            if(sum<0) sum=0;
        }
         sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            minsum=min(minsum,sum);
            if(sum>0)sum=0;
        }

        int maxsum2=totalsum-minsum;

        if(maxsum < 0) return maxsum;
        return max(maxsum,maxsum2);
    }
};