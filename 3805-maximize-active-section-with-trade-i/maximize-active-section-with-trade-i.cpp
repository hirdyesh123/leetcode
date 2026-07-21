class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int activeCount = count(s.begin(), s.end(), '1');

        // Block of '0'
        vector<int> inactiveBlocks;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0')
                    i++;
                inactiveBlocks.push_back(i - start);
            } else {
                i++;
            }
        }


        int maxZeros = 0;
        for (size_t i = 1; i < inactiveBlocks.size(); i++) {
            maxZeros = max(maxZeros, inactiveBlocks[i] + inactiveBlocks[i - 1]);
        }

        return activeCount + maxZeros;
    }
};