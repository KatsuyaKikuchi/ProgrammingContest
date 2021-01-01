#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

class Prime {
public:
    Prime(ll n) {
        mPrimeTbl.clear();
        vector<bool> u(n, false);
        for (ll i = 2; i <= n; ++i) {
            if (u[i])
                continue;
            mPrimeTbl.push_back(i);
            for (ll p = i; p <= n; p += i)
                u[p] = true;
        }
    }

    ~Prime() {}

    ll num() {
        return static_cast<ll>(mPrimeTbl.size());
    }

    ll get(ll index) {
        return mPrimeTbl[index];
    }

private:
    vector<ll> mPrimeTbl;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    Prime prime(105);

    vector<ll> v(prime.num(), 0);
    FOR(i, N, 1) {
        ll x = i + 1;
        REP(j, prime.num()) {
            while (x % prime.get(j) == 0) {
                v[j]++;
                x /= prime.get(j);
            }
        }
    }

    ll ans = 0;
    {
        // 75
        REP(i, v.size()) {
            if (v[i] >= 74) {
                ans++;
            }
        }
    }
    {
        // 3*25
        REP(i, v.size()) {
            REP(j, v.size()) {
                if (i == j)
                    continue;
                if (v[i] >= 2 && v[j] >= 24)
                    ans++;
            }
        }
    }
    {
        // 5*15
        REP(i, v.size()) {
            REP(j, v.size()) {
                if (i == j)
                    continue;
                if (v[i] >= 4 && v[j] >= 14)
                    ans++;
            }
        }
    }
    {
        // 3*5*5
        REP(i, v.size()) {
            REP(j, v.size()) {
                if (i == j)
                    continue;
                FOR(k, v.size(), j + 1) {
                    if (k == j || i == k)
                        continue;
                    if (v[i] >= 2 && v[j] >= 4 && v[k] >= 4)
                        ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}