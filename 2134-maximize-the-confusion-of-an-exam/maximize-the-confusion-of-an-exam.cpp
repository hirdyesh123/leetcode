class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int ans=0;
        int left=0;
        int right=0;
        int check=0;
        while(right<s.size()){                //pass 1 where we make false true;
           if(s[right]=='F') check++;
           while(check>k){
            if(s[left]=='F') check--;
            left++;
           }
           ans=max(ans,right-left+1);
           right++;
        }
        
        left=0;right=0;check=0;

        while(right<s.size()){                //pass 2 where we make true false;
           if(s[right]=='T') check++;
           while(check>k){
            if(s[left]=='T') check--;
            left++;
           }
           ans=max(ans,right-left+1);
           right++;
        }

      return ans;
    }
};