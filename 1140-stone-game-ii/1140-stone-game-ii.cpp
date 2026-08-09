class Solution {
    long long f(int idx, int m, vector<int>& piles,
               vector<long long>& suffix,
               vector<vector<long long>>& dp) {

        int n = piles.size();

        if (idx >= n)
            return 0;

        if (dp[idx][m] != -1)
            return dp[idx][m];

        long long ans = 0;

        
        for (int i = 1; i <= min(2 * m, n - idx); i++) {

            long long taken = suffix[idx] - suffix[idx + i];

         
            long long opponent =
                f(idx + i, max(m, i), piles, suffix, dp);

           
            ans = max(ans,
                      suffix[idx] - opponent);
        }

        return dp[idx][m] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        
        vector<long long> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

       
        vector<vector<long long>> dp(
            n, vector<long long>(n + 1, -1)
        );

        return f(0, 1, piles, suffix, dp);
    }
};