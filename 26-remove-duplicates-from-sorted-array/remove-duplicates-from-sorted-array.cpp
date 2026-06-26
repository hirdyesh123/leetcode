class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
       int left=0;
       int right=0;
       while(right<nums.size()){
          while(right<nums.size() &&nums[left]==nums[right]) right++;
          left++;
          if(right<nums.size())nums[left]=nums[right];
       }
       return left;
    }
};