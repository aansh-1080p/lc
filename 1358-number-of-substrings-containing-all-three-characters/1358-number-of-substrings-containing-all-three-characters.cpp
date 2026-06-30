class Solution {
public:
    int numberOfSubstrings(string s) {
    int n = s.size();
    int count[3] = {0}; 
    int res = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        count[s[right] - 'a']++;
        while (count[0] && count[1] && count[2]) {
            res += n - right;      
            count[s[left] - 'a']--; 
            left++;
        }
    }
    return res;
}
};