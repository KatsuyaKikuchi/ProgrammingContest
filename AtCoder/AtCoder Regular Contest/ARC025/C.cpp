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

Vertex V[2505];
ll C[2505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, R, T;
    cin >> N >> M >> R >> T;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.push_back(pll(b, c));
        V[b].node.push_back(pll(a, c));
    }

    ll ans = 0;
    REP(i, N) {
        vector<ll> v;
        REP(j, N) {
            C[j] = INF;
        }
        C[i] = 0;
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(i, 0));
        while (!q.empty()) {
            pll t = q.top();
            q.pop();
            if (C[t.first] < t.second)
                continue;
            if (t.second > 0) {
                v.push_back(t.second);
            }
            REP(j, V[t.first].node.size()) {
                ll n = V[t.first].node[j].first;
                ll cost = V[t.first].node[j].second + t.second;
                if (C[n] <= cost)
                    continue;
                C[n] = cost;
                q.push(pll(n, cost));
            }
        }
        sort(v.begin(), v.end());

        REP(j, v.size()) {
            ll ok = v.size(), ng = -1;
            while (abs(ok - ng) > 1) {
                ll mid = (ok + ng) / 2;
                if (v[mid] * T > v[j] * R)
                    ok = mid;
                else
                    ng = mid;
            }
            ans += v.size() - ok;
            if (ok <= j)
                ans--;
        }
    }
    cout << ans << endl;
    return 0;
}