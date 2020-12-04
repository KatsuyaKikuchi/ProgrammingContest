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

bool solve() {
    ll N, A, B, DA, DB;
    cin >> N >> A >> B >> DA >> DB;
    A--;
    B--;
    vector<Vertex> V(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    if (DB <= DA)
        return true;
    {
        vector<ll> cost(N, INF);
        cost[A] = 0;
        queue<ll> q;
        q.push(A);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            ll cst = cost[t] + 1;
            REP(i, V[t].node.size()) {
                ll nxt = V[t].node[i];
                if (cost[nxt] <= cst)
                    continue;
                cost[nxt] = cst;
                q.push(nxt);
            }
        }
        if (cost[B] <= DA)
            return true;
    }

    {

        ll s = 0;
        REP(i, N) {
            if (V[i].node.size() == 1) {
                s = i;
                break;
            }
        }
        {
            vector<ll> cost(N, INF);
            queue<ll> q;
            q.push(s);
            cost[s] = 0;
            while (!q.empty()) {
                ll t = q.front();
                q.pop();
                ll cst = cost[t] + 1;
                REP(i, V[t].node.size()) {
                    ll nxt = V[t].node[i];
                    if (cost[nxt] <= cst)
                        continue;
                    cost[nxt] = cst;
                    q.push(nxt);
                }
            }
            REP(i, N) {
                if (cost[s] < cost[i])
                    s = i;
            }
        }
        ll len = 0;
        {
            vector<ll> cost(N, INF);
            queue<ll> q;
            q.push(s);
            cost[s] = 0;
            while (!q.empty()) {
                ll t = q.front();
                q.pop();
                ll cst = cost[t] + 1;
                REP(i, V[t].node.size()) {
                    ll nxt = V[t].node[i];
                    if (cost[nxt] <= cst)
                        continue;
                    cost[nxt] = cst;
                    q.push(nxt);
                }
            }
            REP(i, N) {
                len = std::max(len, cost[i]);
            }
        }

        if (DB > DA * 2 && len > DA * 2)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}