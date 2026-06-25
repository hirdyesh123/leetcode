class Solution {
public:
    bool check(char x){
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u') return true;

        return false;
    }
    int maxVowels(string s, int k) {
      int ans=0;
      int vowelcount=0;
      int left=0;
      int right=0;
      while(right<s.size()){
        if(check(s[right])) vowelcount++;

        if((right-left+1) == k){
            ans=max(ans,vowelcount);
            if(check(s[left])) vowelcount--;
            left++;

        }
        right++;
      }  


      return ans;
    }
};