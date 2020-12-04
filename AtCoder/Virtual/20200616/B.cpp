#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};
bool U[105];
Vertex V[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    ll ans = 0;
    REP(i, N) {
        if (U[i])
            continue;

        queue<pll> q;
        q.push(pll(i, -1));
        U[i] = true;
        bool e = true;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            for (auto &n : V[t.first].node) {
                if (n == t.second)
                    continue;
                if (U[n]) {
                    e = false;
                    break;
                }
                U[n] = true;
                q.push(pll(n, t.first));
            }
        }

        if (e)
            ans++;
    }

    cout << ans << endl;
    return 0;
}