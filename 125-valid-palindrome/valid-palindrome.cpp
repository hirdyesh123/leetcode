class Solution {
public:
    bool isPalindrome(string s) {
        for (char &c : s) {
           c = tolower(c);
         }
        int left=0;
        int right=s.size();
         while(left<right){
           char ch1=s[left];
           char ch2=s[right];
           if( ! (( ch1>='a' && ch1<='z') || (ch1>='0'&& ch1<='9')) ) left++;
           else if( ! (( ch2>='a' && ch2<='z') || (ch2>='0'&& ch2<='9')) ) right--;
           else {
                if(s[left]==s[right]) {
                    left++;
                    right--;
                }
                else return false;
           }
         }
         return true;
    }
};