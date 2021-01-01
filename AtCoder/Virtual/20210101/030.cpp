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
    Prime prime(N + 1);
    vector<ll> v(prime.num(), 0);
    FOR(i, N, 1) {
        ll x = i + 1;
        REP(j, prime.num()) {
            ll p = prime.get(j);
            while (x % p == 0) {
                x /= p;
                v[j]++;
            }
        }
    }
    ll ans = 1;
    REP(i, v.size()) {
        ans = (ans * (v[i] + 1)) % MOD;
    }
    cout << ans << endl;

    return 0;
}