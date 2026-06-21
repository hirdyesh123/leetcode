class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            if(nums[left]+nums[right]>limit){
                ans++;
                right--;
            }
            else{
                ans++;
                left++;
                right--;
            }
        }
        return ans;
    }
};