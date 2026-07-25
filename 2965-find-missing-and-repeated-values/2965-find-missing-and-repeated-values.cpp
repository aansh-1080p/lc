class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n*n +1,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                freq[grid[i][j]]++;
            }
        }
        int rep,mis;
        for(int i=0;i<=n*n;i++){
            if(freq[i]==2) rep=i;
            if(freq[i]==0) mis=i;

        }
        return {rep,mis};
    }
};