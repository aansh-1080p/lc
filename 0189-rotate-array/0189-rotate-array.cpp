class Solution {
public:
    void rotate(vector<int>& v1, int k) {
        int n = v1.size();
        k %= n;
       vector<int> v2(n);
        int j = 0;

        for(int i = k; i < n; i++) {
            v2[i] = v1[j];
            j++;
        }

        for(int i = 0; i < k; i++) {
            v2[i] = v1[j];
            j++;
        }

        v1 = v2;
    }
};