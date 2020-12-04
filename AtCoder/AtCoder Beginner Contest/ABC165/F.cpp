#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
struct Vertex {
    vector<ll> node;
};

vector<ll> v;
Vertex V[200005];
ll C[200005];

void dfs(ll index = 0, ll par = -1) {
    ll a = A[index];
    ll mi = lower_bound(v.begin(), v.end(), a) - v.begin();
    ll t = v[mi];
    v[mi] = a;
    C[index] = lower_bound(v.begin(), v.end(), INF) - v.begin();
    REP(i, V[index].node.size()) {
        ll n = V[index].node[i];
        if (n == par)
            continue;
        dfs(n, index);
    }
    v[mi] = t;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        C[i] = 0;
    }
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    REP(i, N + 5) {
        v.push_back(INF);
    }
    dfs();

    REP(i, N) {
        cout << C[i] << endl;
    }
    return 0;
}