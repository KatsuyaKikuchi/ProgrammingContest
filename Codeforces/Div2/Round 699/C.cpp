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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N), C(M);
    REP(i, N) {
        cin >> A[i];
        A[i]--;
    }
    REP(i, N) {
        cin >> B[i];
        B[i]--;
    }
    REP(i, M) {
        cin >> C[i];
        C[i]--;
    }
    vector<stack<ll>> cnt(N);
    ll last = -1;
    REP(i, N) {
        if (A[i] != B[i] && C[M - 1] == B[i]) {
            last = i;
            break;
        }
    }
    if (last < 0) {
        REP(i, N) {
            if (C[M - 1] == B[i])
                last = i;
        }
    }
    if (last < 0) {
        cout << "NO" << endl;
        return;
    }
    REP(i, N) {
        if (A[i] != B[i] && last != i)
            cnt[B[i]].push(i + 1);
    }

    vector<ll> ans(M, last + 1);
    REP(i, M - 1) {
        if (cnt[C[i]].empty())
            continue;
        ans[i] = cnt[C[i]].top();
        cnt[C[i]].pop();
    }

    bool check = true;
    REP(i, N) {
        if (!cnt[i].empty())
            check = false;
    }
    if (!check) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    REP(i, M) {
        cout << ans[i] << " ";
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