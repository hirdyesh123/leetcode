class Solution {
public:
    long long sumAndMultiply(int n) {
        int rev=0;
        int temp=n;
        int sum=0;
        int rev2=0;
        while(temp>0){
            int val=temp%10;
            sum+=val;
            temp=temp/10;
           if(val!=0) rev=rev*10+val;

        }
        
        while(rev>0){
            int val=rev%10;
            rev=rev/10;
            rev2=rev2*10+val;
        }
       return 1LL*rev2*sum;
    }
};