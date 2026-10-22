class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int pos0=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) {pos0=i;break;}
        }
        bool inc=true;
        // bool dec=true;
        for(int i=0;i<n;i++){
            if(nums[(pos0 + i)%n]!=i) {inc = false;break;}
            
        }
        bool dec = true;
        for(int i=0;i<n;i++){
            if(nums[(pos0+i)%n]!=(n-i)%n){
                dec=false;
                break;
            }
        }
        if(inc) return min(pos0,n-pos0+2);
        // if(dec && inc) return min(pos0 + 1,1+(n-1-pos0));
        if(dec) return min(n-pos0,pos0+2);
        return -1;
    }
};