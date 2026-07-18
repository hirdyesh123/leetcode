class Solution {
public:
    int doit(int a,int b, char x){
        if(x=='*') return (a*b);
        else if(x=='+') return (a+b);
        else if(x=='/') return (b/a);
        else  return (b-a);
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(int i=0;i<tokens.size();i++){ 
           string x=tokens[i];
           
           if(x=="+" || x=="*" || x=="-" || x=="/"){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();

            st.push(doit(a,b,x[0]));
           }
           else {
            st.push(stoi(x));
           }
        }

        return st.top();
    }
};