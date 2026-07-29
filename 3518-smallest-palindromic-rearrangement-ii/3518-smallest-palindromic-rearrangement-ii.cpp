class Solution {
public:
    #define ll long long
    int MOD = 1e9+7;
    ll exp(ll base, ll exp) {
        ll ans = 1;
        while (exp > 0) {
            if (exp & 1) {
                ans = (ans * base) % MOD;
            }
            exp /= 2;
            base = (base * base) % MOD;
        }
        return ans;
    }
    ll modInverse(ll b) {
        return exp(b, MOD - 2);
    }
    ll modDivision(ll a, ll b) {
        return (a * modInverse(b)) % MOD;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.length();

        if (n == 1) {
            return (k == 1) ? s : "";
        }

        std::string perm = s.substr(0, n / 2);
        std::vector<int> cnts(26, 0);
        for (int i = 0; i < perm.size(); i++) {
            cnts[s[i] - 'a']++;
        }

        std::vector<ll> fact(perm.size() + 1, 1);
        std::vector<double> logFact(perm.size() + 1, 0);

        for (int i = 1; i < fact.size(); i++) {
            fact[i] = (i * fact[i - 1]) % MOD;
            logFact[i] = logFact[i - 1] + std::log(i);
        }

        ll length = perm.size();
        ll base = 1;
        double logBase = 0;

        for (int i = 0; i < 26; i++) {
            base = (base * fact[cnts[i]]) % MOD;
            logBase += logFact[cnts[i]];
        }

        ll permute = modDivision(fact[length], base);
        double logK = std::log(k);

        int val = 0;
        std::string ans;

        while (val < k && length > 0) {
            bool found = false;

            for (int i = 0; i < 26; i++) {
                if (cnts[i] == 0) {
                    continue;
                }

                ll nextPermute = (modDivision(permute, length) * cnts[i]) % MOD;

                double newLogBase =
                    logBase - logFact[cnts[i]] + logFact[cnts[i] - 1];
                double nextLogK = logFact[length - 1] - newLogBase;

                ll nextVal = val + nextPermute;

                if (nextVal >= k || nextLogK >= logK) {
                    ans += ('a' + i);
                    logBase = newLogBase;
                    cnts[i]--;
                    length--;
                    permute = nextPermute;
                    found = true;

                    if (length == 0) {
                        val = nextVal;
                    }
                    break;
                }

                val = nextVal;
            }

            if (!found) {
                return "";
            }
        }
        if (val != k) {
            return "";
        }
        std::string ansRev = ans;
        std::reverse(ansRev.begin(), ansRev.end());

        return (n & 1) ? ans + s[n / 2] + ansRev : ans + ansRev;
    }
};
//its done bro 
