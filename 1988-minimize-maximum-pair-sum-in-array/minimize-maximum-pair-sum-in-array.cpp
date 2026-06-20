class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        int maxsum=INT_MIN;
        while(start<end){
            int sum=nums[start]+nums[end];
            maxsum=max(maxsum,sum);
            start++;
            end--;;
        }
        return maxsum;
    }
};