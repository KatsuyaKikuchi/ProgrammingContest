#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N, C;
    cin >> N >> C;
    ll mn = N - 1;
    ll mx = (N + 1) * N / 2 - 1;
    if (C < mn || mx < C) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<ll> L(N);
    REP(i, N) {
        L[i] = i + 1;
    }
    C -= N - 1;

    for (ll i = N - 2; i >= 0; --i) {
        ll cnt = std::min(N - i - 1, C);
        REP(n, (cnt + 1) / 2) {
            swap(L[i + n], L[i + cnt - n]);
        }

        C -= cnt;
    }

    REP(i, N) {
        cout << L[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(i, Q) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}