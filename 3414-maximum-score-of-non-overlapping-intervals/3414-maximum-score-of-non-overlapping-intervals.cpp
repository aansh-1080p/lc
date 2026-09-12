class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> arr;

        for (int i = 0; i < n; i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            int weight = intervals[i][2];

            arr.push_back({right, left, weight, i});
        }

        sort(arr.begin(), arr.end());

        vector<int> rightEnds(n);

        for (int i = 0; i < n; i++) {
            rightEnds[i] = arr[i][0];
        }

        using State = pair<long long, vector<int>>;

        vector<State> previous(n + 1, {0, {}});

        auto better = [&](const State& a, const State& b) {
            if (a.first != b.first) {
                return a.first > b.first ? a : b;
            }

            return a.second < b.second ? a : b;
        };

        for (int selectedCount = 1; selectedCount <= 4; selectedCount++) {
            vector<State> current(n + 1, {0, {}});

            for (int i = 1; i <= n; i++) {
                int right = arr[i - 1][0];
                int left = arr[i - 1][1];
                int weight = arr[i - 1][2];
                int originalIndex = arr[i - 1][3];

                State skip = current[i - 1];

                int previousCount = lower_bound(
                    rightEnds.begin(),
                    rightEnds.begin() + (i - 1),
                    left
                ) - rightEnds.begin();

                long long previousScore = previous[previousCount].first;
                vector<int> newIndices = previous[previousCount].second;

                newIndices.push_back(originalIndex);
                sort(newIndices.begin(), newIndices.end());

                State take = {
                    previousScore + weight,
                    newIndices
                };

                current[i] = better(skip, take);
            }

            previous = current;
        }

        return previous[n].second;
    }
};