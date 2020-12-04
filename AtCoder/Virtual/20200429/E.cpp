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
    vector<pll> node;
};

Vertex V[100005];
bool U[100005];
ll S[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        V[l].node.push_back(pll(r, d));
        V[r].node.push_back(pll(l, -d));
    }

    bool exist = true;
    REP(i, N) {
        if (U[i])
            continue;
        U[i] = true;
        queue<pll> q;
        q.push(pll(i, 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            REP(i, V[t.first].node.size()) {
                pll n = V[t.first].node[i];
                ll nxt = n.first;
                ll cost = n.second + t.second;
                if (U[nxt]) {
                    if (S[nxt] != cost)
                        exist = false;
                    continue;
                }
                U[nxt] = true;
                S[nxt] = cost;
                q.push(pll(nxt, cost));
            }
        }
    }

    if (exist)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}