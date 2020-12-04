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

Vertex V[100005];
bool U[100005];

int main() {
    ll N, K;
    cin >> N >> K;
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    ll ans = 1;
    memset(U, 0, sizeof(U));
    queue<pll> q;
    q.push(pll(0, K));
    while (!q.empty()) {
        pll t = q.front();
        q.pop();

        if (K - t.second < 0)
            ans = 0;
        ans = (ans * (t.second)) % MOD;
        U[t.first] = true;
        ll s = 1;
        if (t.first != 0)
            s++;
        REP(i, V[t.first].node.size()) {
            ll n = V[t.first].node[i];
            if (U[n])
                continue;

            q.push(pll(n, K - s));
            s++;
        }
    }
    cout << ans << endl;
    return 0;
}