class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        map<int,int> mp;
        for(auto h: hand) mp[h]++;
        if(hand.size() % gs !=0) return false;
        for(auto [h,freq] : mp){
            if(freq==0) continue;
            while(freq--){
                for (int cur = h; cur < h + gs; cur++) {
                    if (mp[cur] == 0) return false;
                    mp[cur]--;
                }
            }
        }
        return true;
            }
};