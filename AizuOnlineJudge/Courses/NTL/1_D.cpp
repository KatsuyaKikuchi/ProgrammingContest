//!******************************************************
//! MEMO
//! 包除原理
//!******************************************************

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

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
    ll N;
    cin >> N;
    Prime prime(100005);

    vector<ll> v;
    ll t = N;
    REP(i, prime.num()) {
        ll p = prime.get(i);
        ll n = 0;
        while (t % p == 0) {
            t /= p;
            n++;
        }
        if (n > 0)
            v.push_back(p);
    }

    if (t > 1)
        v.push_back(t);

    ll ans = N;
    FOR(i, pow(2LL, v.size()), 1) {
        ll p = 1;
        ll m = 0;
        REP(j, v.size()) {
            if ((i >> j) & 1) {
                p *= v[j];
                m++;
            }
        }

        ll n = N / p;
        if (m % 2 == 1)
            ans -= n;
        else
            ans += n;
    }
    cout << ans << endl;
    return 0;
}