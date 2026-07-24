class Solution {
    static constexpr int m{2048};

public:
    static int uniqueXorTriplets(const std::vector<int>& nums) {
        const int n{static_cast<int>(nums.size())};
        bool singles[1501]{};
        bool duos[m]{};
        bool trios[m]{};

        for (int i{0}; i < n; ++i) {
            const int a{nums[i]};
            
            if (singles[a]) {
                continue;
            }

            singles[a] = true;

            for (int j{i}; j < n; ++j) {
                const int b{a ^ nums[j]};

                if (duos[b]) {
                    continue;
                }

                duos[b] = true;

                for (int k{j}; k < n; ++k) {
                    trios[b ^ nums[k]] = true;
                }
            }
        }

        return std::accumulate(trios, trios + m, 0);
    }
};