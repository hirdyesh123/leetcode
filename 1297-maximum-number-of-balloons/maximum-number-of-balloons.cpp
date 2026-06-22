class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans=0;
        string check= "balloon";
        unordered_map<char,int>m;
        for(auto i:text){
            m[i]++;
        }
        int i=0;
        while(m[check[i]]!=0 ){
              bool flag=true;
            for(auto j:check){
             if(m[j]!=0) m[j]--;
             else flag=false;
            }

            if(flag==true) ans++;
        }
       return ans;
    }
};