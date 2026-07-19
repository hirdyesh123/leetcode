class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool>taken(26,false);
        vector<int>right(26,0);
        string ans="";
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            right[idx]=i;
        }
        
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
           
           if(taken[idx]==true) continue;

           while(ans.size()>0 && s[i]<ans.back() && right[ans.back()-'a']>i){
            taken[ans.back()-'a']=false;
            ans.pop_back();
           } 
           ans=ans+s[i];
           taken[idx]=true;
        }
        return ans;
    }
};