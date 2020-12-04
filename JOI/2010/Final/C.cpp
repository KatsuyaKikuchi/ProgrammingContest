#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, L;
    cin >> N >> L;

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first < b.first; });
    REP(i, N) {
        cin >> A[i];
        q.push(pll(A[i], i));
    }

    ll ans = 0;
    memset(B, 0, sizeof(B));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        ll m = 0;
        if (t.second > 0)
            m = std::max(m, B[t.second - 1]);
        if (t.second < N - 1)
            m = std::max(m, B[t.second + 1]);
        ll p = m + (L - t.first);
        B[t.second] = p;
        ans = std::max(B[t.second], ans);
    }

    cout << ans << endl;
    return 0;
}