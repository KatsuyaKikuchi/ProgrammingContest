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
    cin.tie(0);
    Prime prime(1000005);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    vector<pll> p;
    REP(i, prime.num()) {
        ll t = prime.get(i);
        ll n = 0;
        while (N % t == 0) {
            n++;
            N /= t;
        }
        if (n > 0)
            p.push_back(pll(t, n));
    }

    if (N > 1)
        p.push_back(pll(N, 1));

    ll ans = 0;
    REP(i, p.size()) {
        //cout << p[i].first << " " << p[i].second << endl;
        ll n = 0;
        ll m = 1;
        while (n + m <= p[i].second) {
            n += m;
            m++;
        }
        ans += m - 1;
    }
    cout << ans << endl;
    return 0;
}