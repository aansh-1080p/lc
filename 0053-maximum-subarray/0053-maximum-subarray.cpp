class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        int curr=0;

        for(int i=0;i<nums.size();i++){
        curr+=nums[i];
        if(mx<curr) mx = curr;
        if(curr<0) curr=0;

        }
    return mx;
    }
};