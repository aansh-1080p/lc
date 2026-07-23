class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;

        for (int num : set) {
            if (!set.count(num - 1)) {
                int current = num;
                int streak = 1;
                while (set.count(current + 1)) {
                    current++;
                    streak++;
                }
                longest = std::max(longest, streak);
            }
        }

        return longest;
    }
};