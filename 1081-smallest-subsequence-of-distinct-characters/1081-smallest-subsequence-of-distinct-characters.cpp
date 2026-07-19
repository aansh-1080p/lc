class Solution {
public:
    string smallestSubsequence(string s) {
        int count[26] = {0};
        bool visited[26] = {false};
        char st[10001];
        int top = -1;
        for (char c : s) {
            count[c - 'a']++;
        }
        for (char c : s) {
            int idx = c - 'a';
            count[idx]--;
            if (visited[idx]) continue;
            while (top >= 0 &&
                   st[top] > c &&
                   count[st[top] - 'a'] > 0) {
                visited[st[top] - 'a'] = false;
                top--;
            }
            st[++top] = c;
            visited[idx] = true;
        }
        return string(st, top + 1);
    }
};