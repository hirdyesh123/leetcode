class Solution {
public:
    vector<int> replaceElements(vector<int>&nums ) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int maxe=-1;
            for(int j=i+1;j<nums.size();j++){
                maxe=max(maxe,nums[j]);
            }
            ans.push_back(maxe);
        }
        return ans;
    }
};