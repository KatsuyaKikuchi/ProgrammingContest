#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, D, A;
pll T[200005];
vector<ll> X;

ll pos(ll x) {
    ll ok = N - 1, ng = -1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (T[mid].first >= x)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    cin >> N >> D >> A;
    REP(i, N) {
        cin >> T[i].first >> T[i].second;
    }
    sort(T, T + N, [](pll a, pll b) { return a.first < b.first; });

    REP(i, N) {
        X.push_back(T[i].first);
        X.push_back(T[i].first + 2LL * D);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    vector<ll> S(X.size() + 1, 0);
    ll s = 0;
    ll ans = 0;
    REP(i, X.size()) {
        s += S[i];
        ll xi = pos(X[i]);
        if (T[xi].first != X[i])
            continue;
        ll h = T[xi].second - s;
        if (h <= 0)
            continue;

        ll n = (h + A - 1) / A;
        s += n * A;
        ans += n;
        ll index = lower_bound(X.begin(), X.end(), X[i] + 2LL * D) - X.begin();
        S[index + 1] += -(n * A);
    }
    cout << ans << endl;
    return 0;
}