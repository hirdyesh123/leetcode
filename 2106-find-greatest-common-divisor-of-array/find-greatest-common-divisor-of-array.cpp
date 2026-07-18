class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small=INT_MAX;
        int large=INT_MIN;
        for(int i=0;i<nums.size();i++){
            small=min(nums[i],small);
            large=max(nums[i],large);
        }

        return gcd(small,large);
    }
};