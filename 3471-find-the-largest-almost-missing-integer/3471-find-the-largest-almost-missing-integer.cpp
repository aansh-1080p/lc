class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        vector<int> arr;

        if (k == 1) {
            for (int x : nums) {
                if (count(nums.begin(), nums.end(), x) == 1) {
                    arr.push_back(x);
                }
            }
        } 
        else{
            for (int x : {nums[0], nums[n - 1]}) {
                if (count(nums.begin(), nums.end(), x) == 1) {
                    arr.push_back(x);
                }
            }
        }
        if(!arr.empty()) return *max_element(arr.begin(), arr.end());
        return -1;
    }

}
;