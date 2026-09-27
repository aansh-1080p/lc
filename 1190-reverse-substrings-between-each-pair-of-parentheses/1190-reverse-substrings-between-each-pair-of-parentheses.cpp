class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == ')'){
                string temp = "";
                while(st.top() != '('){temp += st.top(); st.pop();}
                st.pop();
                for(char x: temp) st.push(x);
            }else{
                st.push(c);
            }
        }

        string res = "";
        while(!st.empty()){res += st.top(); st.pop();}

        reverse(res.begin(), res.end());

        return res;
    }
};
