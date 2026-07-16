class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int currmax=nums[0];
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            currmax=max(nums[i],currmax);
            int temp=gcd(currmax,nums[i]);
            nums[i]=temp;
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int temp=gcd(nums[i],nums[j]);
            sum+=temp;

            i++;
            j--;
        }

        return sum;
    }
};