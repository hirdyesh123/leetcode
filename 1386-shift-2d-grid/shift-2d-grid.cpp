class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();
        int te= m*n;
        k=k%te;
        for(int x=1;x<=k;x++){
            int temp=grid[m-1][n-1];

            for(int i=m-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                   if(j==0 && i==0) grid[i][j]=temp;
                   else if(j==0) grid[i][j]=grid[i-1][n-1];
                   else grid[i][j]=grid[i][j-1];
                }
            }
        }
        return grid;
    }
};