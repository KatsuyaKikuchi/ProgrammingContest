#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> V(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].push_back(b);
    }

    ll ans = 0;
    REP(i, N) {
        vector<bool> U(N, false);
        U[i] = true;
        queue<ll> q;
        q.push(i);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            for (auto &n : V[t]) {
                if (U[n])
                    continue;
                U[n] = true;
                q.push(n);
            }
        }
        REP(j, N) {
            if (U[j])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}