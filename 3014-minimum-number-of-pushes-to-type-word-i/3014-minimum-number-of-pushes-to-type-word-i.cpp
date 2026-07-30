class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0, n = word.size(), row = 1;
        int quotient = n / 8;
        int remainder = n % 8;
        while (quotient--) {
            ans += 8 * row;
            row++;
        }
        ans += remainder * row;
        return ans;
    }
};