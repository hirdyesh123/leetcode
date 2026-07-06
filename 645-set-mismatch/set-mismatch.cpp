class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>map;
         int miss=0;
         int dup=0;
        for(auto x :nums){
            map[x]++;
        }

        for(int i=1;i<=nums.size();i++){
            if(map.find(i)!=map.end()){
                if(map[i]>1) dup=i;
            }
            else miss=i;
        }

        return {dup,miss};
    }
};