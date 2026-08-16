class Solution {
    private:
    bool sovle(vector<int>& nums, int threshold, int mid){
        int sum=0;
        for(int x:nums){
            sum+=ceil((double)x/mid);
        }
        return sum<=threshold;

    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int div=r;
        while(l<r){
           int mid = l + (r - l) / 2;
            if(sovle(nums,threshold,mid)){
                div=mid;
                r = mid;
            }
            else{
                l=mid+1;
            }

        }
        return div;
    }
};