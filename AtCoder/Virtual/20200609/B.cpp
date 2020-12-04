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

ll S[100005];
bool P[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    memset(S, 0, sizeof(S));
    memset(P, 0, sizeof(P));
    Prime prime(100005);
    REP(i, prime.num()) {
        P[prime.get(i)] = true;
    }

    REP(i, 100004) {
        if (P[i] && P[(i + 1) / 2])
            S[i]++;
        S[i + 1] += S[i];
    }
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll l, r;
        cin >> l >> r;
        cout << S[r] - S[l - 1] << endl;
    }
    return 0;
}