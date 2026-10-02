class Solution {
private:
    void generate(string s, int open, int close, int n,
                  vector<string>& ans) {

        // Complete valid parentheses string
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add '('
        if (open < n) {
            generate(s + "(", open + 1, close, n, ans);
        }

        // Add ')'
        if (close < open) {
            generate(s + ")", open, close + 1, n, ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        generate("", 0, 0, n, ans);

        return ans;
    }
};