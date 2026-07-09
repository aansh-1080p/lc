class Solution {
public:
    int countCommas(int n) {
         int ans = 0 ; 
        for( int i = 1 ; i <= n; i++ ) {
            int d = to_string(i).size() ; 
            ans += ( d - 1 ) / 3 ; 
        }
        return ans ; 
    }
};