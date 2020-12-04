#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Edge {
    ll u;
    ll v;
    ll cost = 1000000;

    ll pair(ll index) {
        if (u == index)
            return v;
        if (v == index)
            return u;
        return -1;
    }
};

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<Edge> E(M);
    vector<pll> PC, NC;
    REP(i, N - 1) {
        ll c;
        cin >> c;
        if (c > 0)
            PC.push_back(pll(c, i + 1));
        else
            NC.push_back(pll(-c, i + 1));
    }
    sort(PC.begin(), PC.end(), [](pll a, pll b) { return a.first < b.first; });
    sort(NC.begin(), NC.end(), [](pll a, pll b) { return a.first < b.first; });

    queue<pll> pc, nc;
    REP(i, PC.size()) {
        pc.push(PC[i]);
    }
    REP(i, NC.size()) {
        nc.push(NC[i]);
    }
    REP(i, M) {
        cin >> E[i].u >> E[i].v;
        E[i].u--;
        E[i].v--;
    }

    vector<bool> U(N, false);
    vector<ll> C(N, 0);
    C[0] = 0;
    U[0] = true;
    ll count = 1;
    ll max = 0;
    while (count < N) {
        while (!pc.empty() && (nc.empty() || nc.front().first > count)) {
            pll t = pc.front();
            pc.pop();
            ll edge = -1;
            REP(i, M) {
                ll p = E[i].pair(t.second);
                if (p < 0)
                    continue;
                if (!U[p])
                    continue;
                if (edge < 0 || C[E[edge].pair(t.second)] > C[p])
                    edge = i;
            }
            E[edge].cost = t.first - C[E[edge].pair(t.second)];
            C[t.second] = t.first;
            U[t.second] = true;
            max = std::max(t.first, max);
            count++;
        }

        vector<bool> u(N, false);
        ll sum = 0;
        while (!nc.empty() && nc.front().first == count) {
            pll t = nc.front();
            nc.pop();
            ll edge = -1;
            REP(i, M) {
                ll p = E[i].pair(t.second);
                if (p < 0)
                    continue;
                if (!U[p])
                    continue;
                if (edge < 0 || C[E[edge].pair(t.second)] > C[p])
                    edge = i;
            }
            E[edge].cost = max + 1 - C[E[edge].pair(t.second)];
            C[t.second] = max + 1;
            sum++;
            u[t.second] = true;
        }

        REP(i, N) {
            if (u[i])
                U[i] = true;
        }
        count += sum;
        max++;
    }

    REP(i, M) {
        cout << E[i].cost;
        if (i < M - 1)
            cout << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}