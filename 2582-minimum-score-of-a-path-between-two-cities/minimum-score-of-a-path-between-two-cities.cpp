class Solution {
public:
    int minScore(int n, vector<vector<int>>& nums) {
        vector<pair<int,int>>graph[n+1];
        queue<int>q;
        vector<int>isvisited(n+1,0);
        int mindistance=10001;
        for(int i=0;i<nums.size();i++){
            int node=nums[i][0];
            int innode=nums[i][1];
            int weight=nums[i][2];

            graph[node].push_back({innode,weight});
            graph[innode].push_back({node,weight});
        }
        
        isvisited[1]=1;
        q.push(1);

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:graph[node]){
               int innode=i.first;
               int weight= i.second;
                 mindistance=min(mindistance,weight);
               if(isvisited[innode]!=1){
                 q.push(innode);
                 isvisited[innode]=1;
               }
            }
        }
       

       return mindistance;
    }
};