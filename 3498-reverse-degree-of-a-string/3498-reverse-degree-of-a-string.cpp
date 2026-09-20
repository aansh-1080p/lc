class Solution {
public:
    int reverseDegree(string s) {
        int an=0,i,n=s.size(),x;
        for(i=0;i<n;i++){
            x=26-(s[i]-'a');
            an=an+(i+1)*x;
        }
        return an;
    }
};