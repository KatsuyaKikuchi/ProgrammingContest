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

bool P[100005];
ll S[100005];

int main() {
    Prime p(100005);
    memset(P, 0, sizeof(P));
    memset(S, 0, sizeof(S));
    REP(i, p.num()) {
        ll n = p.get(i);
        P[n] = true;
        if (P[(n + 1) / 2])
            S[n]++;
    }

    REP(i, 100002) {
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