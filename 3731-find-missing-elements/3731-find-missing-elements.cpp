class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int lower = nums.front();
        int upper = nums.back();
        for (int i = lower; i <= upper; i++) {
            auto it = lower_bound(nums.begin(), nums.end(), i);

            if (it == nums.end() || *it != i)
                ans.push_back(i);
        }

        return ans;
    }
};