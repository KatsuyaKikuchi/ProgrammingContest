#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void dfs(ll left, ll right, const vector<ll> &A, map<ll, bool> &mp, const vector<ll> &S) {
    if (left > right) {
        return;
    }
    ll s = S[right + 1] - S[left];
    mp[s] = true;
    if (A[left] == A[right]) {
        return;
    }
    ll mid = (A[left] + A[right]) / 2;
    ll ok = left, ng = right;
    while (abs(ok - ng) > 1) {
        ll m = (ok + ng) / 2;
        if (A[m] <= mid)
            ok = m;
        else
            ng = m;
    }

    dfs(left, ok, A, mp, S);
    dfs(ng, right, A, mp, S);
}

bool solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<ll> S(N + 1, 0);
    REP(i, N) {
        S[i + 1] = S[i] + A[i];
    }

    std::map<ll, bool> mp;
    dfs(0, N - 1, A, mp, S);

    REP(_, Q) {
        ll s;
        cin >> s;
        if (mp[s])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
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