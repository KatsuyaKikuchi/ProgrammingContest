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
    ll cnt = 0;
    ll del = 0;
};

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<Vertex> V(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    vector<bool> isLeaf(N, false);
    vector<bool> U(N, true);

    REP(i, N) {
        if (V[i].node.size() == 1) {
            isLeaf[i] = true;
            V[V[i].node[0]].cnt++;
        }
    }

    queue<ll> q;
    REP(i, N) {
        if (V[i].cnt >= K)
            q.push(i);
    }

    ll ret = 0;
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        if (!U[t])
            continue;
        if (V[t].cnt < K)
            continue;
        ll value = V[t].cnt / K;
        ret += value;
        V[t].del += value * K;
        V[t].cnt %= K;
        if (V[t].del >= V[t].node.size() - 1)
            isLeaf[t] = true;
        ll num = 0;
        for (auto &n : V[t].node) {
            if (!U[n])
                continue;
            if (isLeaf[n] && num < value * K) {
                U[n] = false;
                num++;
            }

            if (isLeaf[t] && U[n]) {
                if (++V[n].cnt >= K)
                    q.push(n);
            }
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}