class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=0;
        int sumeven=0;
        int startodd=1;
        int starteven=2;

        for(int i=1;i<=n;i++){
            sumodd+=startodd;
            sumeven+=starteven;

            startodd+=2;
            starteven+=2;
        }


        return gcd(sumodd,sumeven);
    }
};