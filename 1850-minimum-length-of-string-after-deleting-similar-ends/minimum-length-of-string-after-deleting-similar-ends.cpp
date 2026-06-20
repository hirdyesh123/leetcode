class Solution {
public:
    int minimumLength(string s) {
      
        int start=0;
        int end=s.size()-1;
        while(start<end){
            if(s[start]==s[end]){
                char temp=s[start];
               while( start<=end && s[start]==temp) start++;
                while(start<=end && s[end]==temp) end--;
            }
            else break;
        }
         
         if(end-start<0) return 0;
        return end-start+1;
    }
};