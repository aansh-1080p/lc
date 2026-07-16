class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0) ans.emplace_back(nums[i]);
        }
        int k= nums.size()-ans.size();
        while(k--) ans.emplace_back(0);
        nums=ans;
    }
};