#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> B(N, -1);
    vector<ll> L(N, 0);
    REP(i, N) {
        ll a = A[i] - 1;
        ll len = i - B[a];
        L[a] = std::max(L[a], len);
        B[a] = i;
    }

    REP(i, N) {
        ll len = N - B[i];
        L[i] = std::max(L[i], len);
    }

    vector<ll> ans(N, INF);
    REP(i, N) {
        if (L[i] > N)
            continue;
        ll len = L[i] - 1;
        ans[len] = std::min(ans[len], i + 1);
    }
    REP(i, N - 1) {
        ans[i + 1] = std::min(ans[i + 1], ans[i]);
    }
    REP(i, N) {
        if (ans[i] == INF)
            cout << -1;
        else
            cout << ans[i];
        cout << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}