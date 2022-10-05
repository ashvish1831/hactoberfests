// the code contain the solution of the problem call Super Egg Drop in the leetcode platform
class Solution {
public:
    int superEggDrop(int numEggs, int numFloors) {

        vector<int> dp(numEggs+1, 0);

        int dropAttempts;

        for (dropAttempts = 0; dp[numEggs] < numFloors; ++dropAttempts)
        {
            for (int i = numEggs; i > 0; --i) 
            {
                dp[i] += dp[i-1] + 1;
            }
        }
        return dropAttempts; // dp[1] == dropAttempts (they are interchangable)
    }
};