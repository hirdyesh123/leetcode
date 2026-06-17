class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";

        for(auto i:words){
            int sum=0;
            for(auto j: i){
               int temp=(int)j;
               sum+=weights[temp-97];
            }
            int temp=sum%26;
            char temp2=(char)(122-temp);
            ans+=temp2;
        }
       return  ans;
    }
};