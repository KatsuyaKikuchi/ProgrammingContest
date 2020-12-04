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
vector<pll> Cycle;
ll C[100005];
ll P[100005];

void dfs(ll node, ll depth = 0) {
    for (auto &n:V[node].node) {
        if (P[n] == -1) {
            P[n] = depth + 1;
            dfs(n, P[n]);
            continue;
        }
        if (P[n] < P[node] - 1) {
            Cycle.push_back(pll(node, P[node] - P[n] + 1));
            continue;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    REP(i, N) {
        C[i] = INF;
    }

    //! 最短の閉路を見つける
    memset(P, -1, sizeof(P));
    P[0] = 0;
    dfs(0);

    if (Cycle.size() > 0) {
        sort(Cycle.begin(), Cycle.end(), [](pll a, pll b) { return a.second < b.second; });
        vector<ll> v;
        pll c = Cycle[0];
        ll end = -1;
        for (auto &n : V[c.first].node) {
            if (c.second == P[c.first] - P[n] + 1) {
                end = n;
                break;
            }
        }
        v.push_back(c.first);
        ll node = c.first;
        while (node != end) {
            for (auto &n : V[node].node) {
                if (P[n] == P[node] - 1) {
                    v.push_back(n);
                    node = n;
                    break;
                }
            }
        }

        if (v.size() <= K) {
            cout << 2 << endl;
            cout << v.size() << endl;
            REP(i, v.size()) {
                cout << v[i] + 1 << " ";
            }
            cout << endl;
        }
        else {
            cout << 1 << endl;
            ll n = 0;
            for (ll i = 0; i < v.size(); i += 2) {
                cout << v[i] + 1 << " ";
                n++;
                if (n == (K + 1) / 2)
                    break;
            }
        }
        return 0;
    }

    //! 見つけられない場合、グラフは木→2分グラフ
    {
        vector<ll> v, u;
        REP(i, N) {
            if (P[i] % 2 == 0)
                v.push_back(i + 1);
            else
                u.push_back(i + 1);
        }
        if (v.size() < u.size())
            swap(v, u);
        cout << 1 << endl;
        REP(i, (K + 1) / 2) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}