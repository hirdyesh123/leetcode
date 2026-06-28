class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums[0]=1;
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[j])>1){
                nums[i]=nums[j]+1;
            }
            j++;
        }

        return nums[nums.size()-1];
    }
};