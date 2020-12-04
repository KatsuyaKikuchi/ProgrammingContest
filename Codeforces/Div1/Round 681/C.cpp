#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e17;
const ll MAX = 35;

struct Vertex {
    vector<ll> to;
    vector<ll> from;
};
struct Data {
    pll cost;
    ll index;
};

pll D[200005][MAX + 5];
Vertex V[200005];
ll P[MAX + 10];

ll calcCost(pll t) {
    if (t.first == INF)
        return 2LL * INF;
    if (t.first >= MAX) {
        return INF;
    }
    return t.second + P[t.first] - 1;
}

bool lower(pll p, pll t) {
    ll cost0 = calcCost(p);
    ll cost1 = calcCost(t);
    if (cost0 == cost1)
        return p.first == t.first ? p.second < t.second : p.first < t.first;
    return cost0 < cost1;
}

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
        V[a].to.push_back(b);
        V[b].from.push_back(a);
    }
    P[0] = 1;
    REP(i, MAX + 5) {
        P[i + 1] = P[i] * 2LL;
    }
    REP(i, N) {
        REP(j, MAX + 2) {
            D[i][j] = pll(INF, INF);
        }
    }
    D[0][0] = pll(0, 0);

    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) {
        if (a.cost.first == b.cost.first)
            return a.cost.second > b.cost.second;
        return a.cost.first > b.cost.first;
    });
    q.push(Data{pll(0, 0), 0});
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        ll swp = t.cost.first;
        ll dist = t.cost.second;
        ll idx = t.index;
        if (lower(D[idx][std::min(swp, MAX)], t.cost))
            continue;
        FOR(j, MAX + 1, swp + 1) {
            pll cost(j, dist);
            if (!lower(cost, D[idx][j]))
                break;
            D[idx][j] = cost;
            q.push(Data{cost, idx});
        }
        if (swp % 2 == 0) {
            //! to
            for (auto &nxt : V[idx].to) {
                pll cost(swp, dist + 1);
                if (!lower(cost, D[nxt][std::min(swp, MAX)]))
                    continue;
                D[nxt][std::min(swp, MAX)] = cost;
                q.push(Data{cost, nxt});
            }
            for (auto &nxt :V[idx].from) {
                pll cost(swp + 1, dist + 1);
                if (!lower(cost, D[nxt][std::min(MAX, swp + 1)]))
                    continue;
                D[nxt][std::min(swp + 1, MAX)] = cost;
                q.push(Data{cost, nxt});
            }
        }
        else {
            //! from
            for (auto &nxt : V[idx].from) {
                pll cost(swp, dist + 1);
                if (!lower(cost, D[nxt][std::min(swp, MAX)]))
                    continue;
                D[nxt][std::min(swp, MAX)] = cost;
                q.push(Data{cost, nxt});
            }
            for (auto &nxt :V[idx].to) {
                pll cost(swp + 1, dist + 1);
                if (!lower(cost, D[nxt][std::min(MAX, swp + 1)]))
                    continue;
                D[nxt][std::min(swp + 1, MAX)] = cost;
                q.push(Data{cost, nxt});
            }
        }
    }

    ll ans = INF;
    REP(i, MAX) {
        ans = std::min(ans, calcCost(D[N - 1][i]));
    }
    if (ans >= INF) {
        ans = D[N - 1][MAX].second;
        ll p = 1;
        REP(i, D[N - 1][MAX].first) {
            p = (p * 2LL) % MOD;
        }
        p = (p - 1 + MOD) % MOD;
        ans += p;
    }

    cout << (ans % MOD) << endl;
    return 0;
}