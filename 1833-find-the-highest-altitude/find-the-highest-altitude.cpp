class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int pointer1=1;
        int prevsum=gain[0];
        if(gain[0]>0) ans=gain[0];
        while(pointer1<gain.size()){
            int currsum=prevsum+gain[pointer1];
            ans=max(ans,currsum);
            prevsum=currsum;
            pointer1++;
        }
        return ans;
    }
};