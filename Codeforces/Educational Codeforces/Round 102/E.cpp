#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll idx;
    ll cost;
    ll type;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<vector<pll>> V(N);
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].push_back(pll(b, c));
        V[b].push_back(pll(a, c));
    }
    vector<vector<ll>> C(N, vector<ll>(5, INF));
    C[0][0] = 0;
    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.cost > b.cost; });
    q.push(Data{0, 0, 0});
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        ll idx = t.idx;
        ll cost = t.cost;
        ll type = t.type;
        if (C[idx][type] < cost)
            continue;
        REP(i, V[idx].size()) {
            ll nxt = V[idx][i].first;
            ll c = V[idx][i].second;
            if (C[nxt][type] > c + cost) {
                C[nxt][type] = c + cost;
                q.push(Data{nxt, c + cost, type});
            }
            switch (type) {
                case 0: {
                    // -max
                    if (C[nxt][2] > cost) {
                        C[nxt][2] = cost;
                        q.push(Data{nxt, cost, 2});
                    }
                    // +min
                    if (C[nxt][1] > cost + 2LL * c) {
                        C[nxt][1] = cost + 2LL * c;
                        q.push(Data{nxt, cost + 2LL * c, 1});
                    }
                }
                    break;
                case 1: {
                    // -max
                    if (C[nxt][3] > cost) {
                        C[nxt][3] = cost;
                        q.push(Data{nxt, cost, 3});
                    }
                }
                    break;
                case 2: {
                    // +min
                    if (C[nxt][3] > cost + 2LL * c) {
                        C[nxt][3] = cost + 2LL * c;
                        q.push(Data{nxt, cost + 2LL * c, 3});
                    }
                }
                    break;
            }
        }
    }

    FOR(i, N, 1) {
        cout << std::min(C[i][3], C[i][0]) << " ";
    }
    cout << endl;

    return 0;
}