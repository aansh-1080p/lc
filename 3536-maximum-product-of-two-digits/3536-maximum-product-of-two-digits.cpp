class Solution {
    vector<int> v;
    private:
    void sol(int n){
        while(n>0){
            v.emplace_back(n%10);
            n/=10;
        }
    }
public:
    int maxProduct(int n) {
        sol(n);
        int k=v.size();
        sort(v.begin(),v.end());
        return v[k-1]*v[k-2];
    }
};