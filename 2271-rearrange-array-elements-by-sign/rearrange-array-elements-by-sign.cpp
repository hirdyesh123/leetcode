class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posidx=0;
        int negidx=1;
        vector<int>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
              ans[posidx]=nums[i];
              posidx=posidx+2;
            }
            else {
                ans[negidx]=nums[i];
                negidx=negidx+2;
            }
        }
        return ans;
    }
};