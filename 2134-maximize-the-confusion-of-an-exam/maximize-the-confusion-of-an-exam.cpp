class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int left=0;
        int right=0;
        int tcounter=0;
        int fcounter=0;
        int mini=0;
        int ans=0;
        while(right<s.size()){
            if(s[right]=='F') fcounter++;
            else if(s[right]=='T') tcounter++;
             mini=min(fcounter,tcounter);
            while(mini>k){
               if(s[left]=='F') fcounter--;
               else if(s[left]=='T') tcounter--;
               mini=min(fcounter,tcounter);
               left++;
            }
           ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};