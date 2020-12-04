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
    vector<ll> v(N);
    vector<priority_queue<ll, vector<ll>, greater<ll>>> q(N + 1);
    q[N].push(0);
    ll num = 1;
    for (ll i = N; i > 0; --i) {
        while (!q[i].empty()) {
            ll t = q[i].top();
            q[i].pop();
            ll n = (2 * t + i - 1) / 2;
            v[n] = num++;
            if (n - t > 0)
                q[n - t].push(t);
            if (t + i - 1 - n < N)
                q[t + i - 1 - n].push(n + 1);
        }
    }
    REP(i, N) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        solve();
    }
    return 0;
}