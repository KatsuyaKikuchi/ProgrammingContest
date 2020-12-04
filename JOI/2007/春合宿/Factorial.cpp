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

    Prime prime(100000);

    vector<pll> v;
    REP(i, prime.num()) {
        ll p = prime.get(i);
        ll n = 0;
        while (N % p == 0) {
            N /= p;
            n++;
        }
        if (n > 0)
            v.push_back(pll(p, n));
    }
    if (N > 1)
        v.push_back(pll(N, 1));

    ll ans = 0;
    REP(i, v.size()) {
        ans = std::max(ans, v[i].first * v[i].second);
    }
    cout << ans << endl;

    return 0;
}