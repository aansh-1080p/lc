class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long lum = cost1;
       long long minneed = min(need1,need2);
        long long maxneed = max(need1,need2);
        long long ans = 1LL *need1*cost1 + 1LL *need2*cost2;
        long long cost =1LL * minneed*costBoth;
        if(need1>minneed) cost+=1LL *(need1-minneed)* cost1;
        if(need2>minneed) cost+=1LL *(need2-minneed)* cost2;
        ans = min(ans,cost);
        ans = min(ans,1LL * maxneed*costBoth);
        if(need1<=need2){
            cost = 1LL *need1*costBoth +1LL *(need2-need1)*cost2;
            ans = min(ans,cost);
        }
        if(need2<=need1){
            cost = 1LL *need2*costBoth +1LL *(need1-need2)*cost1;
            ans=min(ans,cost);
        }
        return ans;
    }
};