class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;

        for (int num : nums) {
            total += num;
        }

        long long target = total - x;

        if (target < 0) {
            return -1;
        }

        if (target == 0) {
            return n;
        }

        int left = 0;
        long long windowSum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {
            windowSum += nums[right];

            while (windowSum > target) {
                windowSum -= nums[left];
                left++;
            }

            if (windowSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if (maxLen == -1) {
            return -1;
        }

        return n - maxLen;
    }
};