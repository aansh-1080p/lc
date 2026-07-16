class Solution {
public:
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        int maxI=0;
        for(int i=0;i<n;i++){
            maxI=max(maxI,nums[i]);
            prefix[i]=gcd(nums[i],maxI);
        }
        sort(prefix.begin(),prefix.end());

        long long result=0;
        for(int i=0;i<n/2;i++){
            result+=gcd(prefix[i],prefix[n-1-i]);
        }
        return result;
    }
};