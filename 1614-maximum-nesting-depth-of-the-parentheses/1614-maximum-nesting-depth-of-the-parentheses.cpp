class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') {cnt++;
            ans=max(ans,cnt);
            }
            if(s[i]==')') cnt--;
            else continue;
        }
        return ans;
    }
};