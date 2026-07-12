class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        stack<char>st;
        for(auto i:s){
            if(!st.empty() && st.top()==i) st.pop();

            else st.push(i);
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};