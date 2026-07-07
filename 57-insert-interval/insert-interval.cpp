class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        vector<vector<int>>ans;
        bool inserted=false;
        if(nums.size()==0) {
            ans.push_back(newInterval);
            return ans;
        }
        for(auto i:nums){
            if(newInterval[0]<=i[1] && newInterval[0]>=i[0]){     //newnterval ko purana
                newInterval[0]=min(newInterval[0],i[0]);
                newInterval[1]=max(newInterval[1],i[1]);
            } 
            else if(i[0]<=newInterval[1] && i[0]>=newInterval[0]){
                newInterval[0]=min(newInterval[0],i[0]);
                newInterval[1]=max(newInterval[1],i[1]);
            }  

            else {
               if(!inserted && newInterval[1] < i[0]){
                ans.push_back(newInterval);
                inserted=true;
               }
               ans.push_back(i);
              
            }  

            
        }
         if(inserted==false) ans.push_back(newInterval);     
        return ans;
    }
};