class Solution {
public:
    int maxArea(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int ans=0;

        while(left<right){
            int mult=right-left;
            int water=min(nums[left],nums[right])*mult;
            ans=max(ans,water);
            
            if(nums[left]<nums[right]) left++;
            else right--;
        }
        return ans;
    }
};