class Solution {
public:
    vector<vector<int>> dp;

    int f(int left, int right, vector<int>& piles) {
        if (left == right)
            return piles[left];

        if (dp[left][right] != -1)
            return dp[left][right];

        int takeLeft = piles[left] - f(left + 1, right, piles);
        int takeRight = piles[right] - f(left, right - 1, piles);

        return dp[left][right] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));

        return f(0, n - 1, piles) > 0;
    }
};