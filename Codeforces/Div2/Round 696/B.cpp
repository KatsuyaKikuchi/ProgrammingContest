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

ll solve(Prime &prime) {
    ll D;
    cin >> D;
    ll N = prime.num();
    ll p0 = N - 1;
    {
        ll ng = -1;
        while (abs(ng - p0) > 1) {
            ll mid = (ng + p0) / 2;
            if (prime.get(mid) - 1 >= D)
                p0 = mid;
            else
                ng = mid;
        }
    }
    ll p1 = N - 1;
    {
        ll ng = -1;
        while (abs(ng - p1) > 1) {
            ll mid = (ng + p1) / 2;
            if (prime.get(mid) - prime.get(p0) >= D)
                p1 = mid;
            else
                ng = mid;
        }
    }
    ll ans = prime.get(p0) * prime.get(p1);
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    Prime prime(500005);
    REP(_, Q) {
        cout << solve(prime) << endl;
    }
    return 0;
}