class Solution {
public: 
    bool check(string &s,int i){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') return true;
        else if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') return true;

        return false;
    }
    string reverseVowels(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(check(s,start)==true && check(s,end)==true){
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(check(s,start)==true && check(s,end)==false) end--;
            else if(check(s,start)==false && check(s,end)==true) start++;
            else {
                start++;
                end--;
            }
            
        }
        return s;
    }
};