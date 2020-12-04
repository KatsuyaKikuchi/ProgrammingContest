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
    ll count = 0;
};

Vertex V[200005];
bool A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        V[x].node.push_back(y);
        V[y].count++;
    }

    memset(A, 0, sizeof(A));
    queue<ll> q;
    REP(i, N) {
        if (V[i].count == 0) {
            q.push(i);
            A[i] = true;
        }
    }

    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        REP(i, V[t].node.size()) {
            ll n = V[t].node[i];
            V[n].count--;
            if (V[n].count < 0) {
                cout << -1 << endl;
                return 0;
            }
            if (V[n].count == 0) {
                q.push(n);
            }
        }
    }
    REP(i, N) {
        if (V[i].count > 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll ans = 0;
    REP(i, N) {
        if (A[i])
            ans++;
    }
    cout << ans << endl;
    REP(i, N) {
        if (A[i])
            cout << "A";
        else
            cout << "E";
    }
    cout << endl;
    return 0;
}