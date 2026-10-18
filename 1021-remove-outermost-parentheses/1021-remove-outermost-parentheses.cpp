class Solution {
public:
    string removeOuterParentheses(string s) {
        string str="";
        int cnt=0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='(') {cnt++;
               if(cnt>1) str+=s[i];
            }
            else {cnt--;
            if(cnt>0)str+=s[i];
            }
           
        }
    return str;
    }
    
};