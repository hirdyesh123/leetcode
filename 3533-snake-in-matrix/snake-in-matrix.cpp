class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans=0;
        for(auto i:commands){
            if(i=="DOWN") ans+=n;
            else if(i=="UP") ans-=n;
            else if(i=="LEFT") ans-=1;
            else  ans+=1;
        }
        return ans;
    }
};