// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int n=s.size();
//         int l = 0, r = 0, mx = 0, ans = 0;
//         for (char c : s) {
//             if (c == '(')
//                 l++;
//             else {
//                 r++;
//             }
//             if (l == r) {
//                 mx = l * 2;
//                 ans = max(mx, ans);
//             }
//             if (r > l)
//                 l = 0, r = 0;
//         }

//         for (int i = n - 1; i >= 0; i--) {
//             if (s[i] == '(')
//                 l++;
//             else
//                 r++;
//             if (l == r)
//             {mx = l*2;
//                 ans = max(ans,mx);
//                 }
//             if (l > r)
//                 l = r = 0;
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0, r = 0, ans = 0;

        for(char c : s) {
            if(c == '(') l++;
            else r++;

            if(l == r)
                ans = max(ans, 2 * l);

            if(r > l)
                l = r = 0;
        }

        l = r = 0;

        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '(') l++;
            else r++;

            if(l == r)
                ans = max(ans, 2 * l);

            if(l > r)
                l = r = 0;
        }

        return ans;
    }
};