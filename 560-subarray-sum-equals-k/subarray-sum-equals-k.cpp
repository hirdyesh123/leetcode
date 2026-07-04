class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        vector<int>prefixsum(nums.size(),0);
        unordered_map<int,int>m;   //key,freq;
        prefixsum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
          prefixsum[i]=nums[i]+prefixsum[i-1];
        }

        for(int i=0;i<prefixsum.size();i++){
             int temp= prefixsum[i]-k;

             if(temp==0) ans++;
             if(m.find(temp)!=m.end()){
                ans+=m[temp];
             }
             m[prefixsum[i]]++;
        }
        return ans;
    }
};