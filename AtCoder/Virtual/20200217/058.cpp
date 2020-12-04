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
    Prime p(N);

    vector<ll> v(p.num(), 1);
    REP(i, N) {
        ll n = i + 1;
        REP(j, p.num()) {
            while (n % (p.get(j)) == 0) {
                n /= p.get(j);
                v[j]++;
            }
            if (n <= 1)
                break;
        }
    }

    ll ans = 1;
    REP(i, v.size()) {
        ans = (ans * v[i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}