#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef __int128 i128;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll M;

//! Sのn進数表記がM以下か？
bool check(string S, ll n) {
    i128 sum = 0;
    i128 p = 1;
    for (ll i = S.length() - 1; i >= 0; --i) {
        ll d = S[i] - '0';
        if (d > 0) {
            i128 t = d * p;
            if (t > M || t < 0)
                return false;
            sum += t;
            if (sum > M)
                return false;
        }
        p = p * n;
        if (p > M || p < 0) {
            p = -1;
        }
    }
    return true;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string X;
    cin >> X;
    cin >> M;
    ll mx = 0;
    REP(i, X.length()) {
        ll d = X[i] - '0' + 1;
        mx = std::max(d, mx);
    }
    if (X.length() == 1) {
        if (mx - 1 <= M) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
        return 0;
    }
    ll ng = M + 1, ok = mx - 1;
    while (abs(ng - ok) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(X, mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok + 1 - mx << endl;
    return 0;
}