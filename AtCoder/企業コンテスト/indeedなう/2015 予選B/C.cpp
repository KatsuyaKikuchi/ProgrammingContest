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
bool U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(0);
    vector<ll> v;
    while (!q.empty()) {
        ll t = q.top();
        q.pop();
        U[t] = true;
        v.push_back(t + 1);
        REP(i, V[t].node.size()) {
            ll n = V[t].node[i];
            if (U[n])
                continue;
            U[n] = true;
            q.push(n);
        }
    }

    cout << v[0];
    REP(i, N - 1) {
        cout << " " << v[i + 1];
    }
    cout << endl;

    return 0;
}