class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int start=1,end=INT_MIN;
        for(int i=0;i<n;i++){
            end=max(end,nums[i]);
        }

        int mid, ans=end;
        while(start<=end){
            mid=start+(end-start)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(nums[i]+mid-1)/mid;
            }
            if(sum<=threshold){
                ans=mid;
                end=mid-1;
            }
            else if(sum>threshold){
                start=mid+1;
            }

        }
        return ans;
    }
};