class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int bache = 0;

        for (int i = 0; i < n; ++i) {
            bool coveredHai = false;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (intervals[j][0] <= intervals[i][0] &&
                    intervals[i][1] <= intervals[j][1]) {
                    coveredHai = true;
                    break;
                }
            }
            if (!coveredHai) ++bache;
        }
        return bache;
    }
};