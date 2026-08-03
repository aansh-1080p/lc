class Solution {
    vector<int> dp;

    int solve(vector<int>& a, int i, int j){
        if(i > j) return 0;

        if(dp[i] != INT_MIN)
            return dp[i];

        int ans = INT_MIN;
        int take = 0;

        for(int k = 0; k < 3 && i + k <= j; k++) {
            take += a[i + k];
            ans = max(ans, take - solve(a, i + k + 1, j));
        }

        return dp[i] = ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int diff = solve(stoneValue, 0, n - 1);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};