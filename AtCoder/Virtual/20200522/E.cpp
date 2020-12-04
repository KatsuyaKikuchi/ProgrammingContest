#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1005][1005];
struct Vertex {
    vector<ll> node;
    ll cnt = 0;
};

Vertex V[1000005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        REP(j, N - 1) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    vector<ll> v;
    REP(i, N) {
        REP(j, N - 2) {
            ll p = std::min(i, A[i][j]) * N + std::max(i, A[i][j]);
            ll nxt = std::min(i, A[i][j + 1]) * N + std::max(i, A[i][j + 1]);
            V[p].node.push_back(nxt);
            V[nxt].cnt++;
            v.push_back(p);
            v.push_back(nxt);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll ans = 0;
    queue<pll> q;
    REP(i, v.size()) {
        if (V[v[i]].cnt == 0)
            q.push(pll(v[i], 0));
    }

    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ans = std::max(ans, t.second);
        for (auto n:V[t.first].node) {
            if (--V[n].cnt == 0)
                q.push(pll(n, t.second + 1));
        }
    }

    REP(i, v.size()) {
        if (V[v[i]].cnt > 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans + 1 << endl;
    return 0;
}