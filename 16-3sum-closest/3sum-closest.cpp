class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int mindiff=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(sum-target);
                if(diff<mindiff){
                    ans=sum;
                    mindiff=diff;
                }

                if(sum<target) j++;
                else k--;
            }
        }
        return ans;
    }
};