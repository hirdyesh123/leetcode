class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        string ans="";
        int start=0;
        unordered_map<int,string>m;
        int i=1;
        while(start<s.size()){
            if(s[start]==' '){
                if(temp!="") {
                    m[i]=temp;
                    temp="";
                    i++;
                }
                while(start < s.size() && s[start]==' ') start++;
                // if(start == s.size()) break;
            }
            if(start<s.size()) temp=temp+s[start];
             start++;
             
        }
        if(temp!="") m[i]=temp;
        int n=m.size();
        for(int i=n;i>=1;i--){
           string temp2=m[i];
           ans=ans+temp2+" ";
        }
        ans.pop_back();
        return ans;
    }
};