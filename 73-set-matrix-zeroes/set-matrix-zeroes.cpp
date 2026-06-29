class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        bool rowcheck=false;
        bool colcheck=false;
        for(int i=0;i<nums[0].size();i++){
            if(nums[0][i]==0){
                rowcheck=true;
                break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i][0]==0){
                colcheck=true;
                break;
            }
        }
         
         for(int i=1;i<nums.size();i++){
            for(int j=1;j<nums[0].size();j++){
                if(nums[i][j]==0){
                    nums[0][j]=0;
                    nums[i][0]=0;
                }
            }
         }

         for(int i=1;i<nums.size();i++){
            for(int j=1;j<nums[0].size();j++){
                if(nums[0][j]==0 || nums[i][0]==0) nums[i][j]=0;
            }
         }
         if(rowcheck==true){
            for(int i=0;i<nums[0].size();i++){
                nums[0][i]=0;
            }
         }
         if(colcheck==true){
            for(int i=0;i<nums.size();i++){
                nums[i][0]=0;
            }
         }
    }
};