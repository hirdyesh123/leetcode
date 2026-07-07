class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        pair<int,int>current={nums[0][0],nums[0][1]};
        int i=1;
        int counter=1;
        while(i<nums.size()){
          int first=nums[i][0];
          int second=nums[i][1];
       
          if(current.second>=first){
             current.first=max(current.first,first);
             current.second=min(current.second,second);
          }
          else {
            counter++;
            current={first,second};
          }
            i++;
        }
        return counter;
    }
};