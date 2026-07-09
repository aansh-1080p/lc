class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if(s.size()>t.size())return false;
        int n=s.size(),m=t.size();
        if(n==1)return true;
        
        vector<int>pre(n,-1);
        vector<int>suf(n,-1);
        int j=0;
        for(int i=0;i<m && j<n;i++){
            if(t[i]==s[j]){
                pre[j]=i;
                j++;
            }
        }
        j=n-1;
        for(int i=m-1;i>=0 && j>=0 ;i--){
            if(t[i]==s[j]){
                suf[j]=i;
                j--;
            }
        }
        if(pre[n-1] != -1)return true;
            
        if(n>1 && pre[n-2]!=-1 && pre[n-2]<m-1)return true;
        if(n>1 && suf[1]!=-1 &&suf[1]>0)return true;
        
        for(int i=1;i<n-1;i++){
            if(pre[i-1]!=-1 && suf[i+1]!=-1 && (pre[i-1]+1 < suf[i+1]))return true;
        }
        return false;
    }
};