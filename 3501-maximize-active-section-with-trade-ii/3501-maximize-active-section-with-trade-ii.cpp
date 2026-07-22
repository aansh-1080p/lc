#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
template <class T> bool umax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++)
            d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++)
            update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1)
                sml = op(sml, d[l++]);
            if (r & 1)
                smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n)
            return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0)
                l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0)
            return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2))
                r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n))
            x++;
        return x;
    }
};

const int INF = 1e9;
const int MX = 5;
using S = array<array<int, MX>, MX>;
S e() {
    S z;
    for (auto &row : z)
        row.fill(-INF);
    FOR(i, 0, MX) z[i][i] = 0;
    return z;
}

S op(S l, S r) {
    S z;
    for (auto &row : z)
        row.fill(-INF);
    FOR(i, 0, MX)
    FOR(k, i, MX) if (l[i][k] > -INF) FOR(j, k, MX) if (r[k][j] > -INF) { //
        umax(z[i][j], l[i][k] + r[k][j]);
    }
    return z;
}

S make(int c) {
    S z;
    for (auto &row : z)
        row.fill(-INF);

    z[0][0] = z[4][4] = z[0][4] = 0;
    if (c == 0) {
        z[0][1] = z[1][1] = 1;
        z[2][3] = z[2][4] = 1;
        z[3][3] = z[3][4] = 1;
    } else {
        z[1][2] = z[2][2] = 0;
    }

    return z;
}

class Solution {
  public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &queries) {
        int n = s.size();
        vector<S> init(n);
        FOR(i, 0, n) init[i] = make(s[i] - '0');
        segtree<S, op, e> seg(init);

        int ones = count(begin(s), end(s), '1');
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            int gain = seg.prod(l, r + 1)[0][4];
            ans.push_back(ones + gain);
        }
        return ans;
    }
};
//not in this world 
