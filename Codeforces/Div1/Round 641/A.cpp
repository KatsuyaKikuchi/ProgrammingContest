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

ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    Prime prime(500);

    ll ans = 1;
    REP(i, prime.num()) {
        ll p = prime.get(i);
        vector<ll> v;
        REP(j, N) {
            ll n = 0;
            while (A[j] % p == 0) {
                n++;
                A[j] /= p;
            }
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        ans *= pow(p, v[1]);
    }
    vector<ll> t(200005, 0);
    REP(i, N) {
        t[A[i]]++;
    }
    REP(i, t.size()) {
        if (t[i] >= N - 1)
            ans *= i;
    }
    cout << ans << endl;
    return 0;
}