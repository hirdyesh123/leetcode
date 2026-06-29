class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
       // if(nums.size()==1) return {-1};
        int maxe=nums[nums.size()-1];
        nums[nums.size()-1]=-1;
        for(int i=nums.size()-2;i>=0;i--){
            int temp=nums[i];
            nums[i]=max(nums[i+1],maxe);
            maxe=max(maxe,temp);
        }
        return nums;
    }
};