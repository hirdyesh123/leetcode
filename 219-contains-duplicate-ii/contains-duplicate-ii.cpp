class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;  //val,idx;

        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            if(m.find(val)!=m.end()){
                int idx=m[val];
                if(abs(i-idx)<=k) return true;
            }
            m[val]=i;
        }

        return false;
    }
};