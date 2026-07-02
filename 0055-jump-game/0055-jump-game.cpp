class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        if (dp[0] == 0 && nums.size() > 1) return false;

        for (int i = 1; i < nums.size() - 1; i++){
            dp[i] = max(dp[i - 1] - 1, nums[i]);
            if (dp[i] >= nums.size() - i - 1) return true;
            if (dp[i] == 0) return false;
        }
        return true;
    }
};