#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e9;

struct Vertex {
    vector<pll> node;
};

Vertex V[100005];
pll D[100005];
ll T[100005];
ll C[200005];
ll S[100005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> D[i].first;
        D[i].second = i;
        T[i] = D[i].first;
    }
    sort(D, D + N, [](pll a, pll b) { return a.first < b.first; });
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(pll(b, i));
        V[b].node.push_back(pll(a, i));
    }

    memset(C, 0, sizeof(C));
    memset(S, -1, sizeof(S));
    REP(i, N) {
        ll c = D[i].first;
        ll v = D[i].second;

        if (S[v] >= 0)
            continue;

        bool exist = false;
        REP(j, V[v].node.size()) {
            //! すでに色付けされている or 同じ最小コストで色付けされていないものを見つける
            ll n = V[v].node[j].first;
            if (S[n] >= 0) {
                exist = true;
                C[V[v].node[j].second] = c;
                S[v] = (S[n] + 1) % 2;
                break;
            }

            if (S[n] == -1 && T[n] == c) {
                exist = true;
                C[V[v].node[j].second] = c;
                S[v] = 0;
                S[n] = 1;
                break;
            }
        }

        if (!exist) {
            cout << -1 << endl;
            return 0;
        }
    }

    REP(i, M) {
        if (C[i] == 0)
            C[i] = INF;
    }

    REP(i, N) {
        if (S[i] == 0)
            cout << "B";
        else
            cout << "W";
    }
    cout << endl;
    REP(i, M) {
        cout << C[i] << endl;
    }

    return 0;
}