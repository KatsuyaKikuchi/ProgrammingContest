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
ll N, M;
Vertex V[10];

bool check(vector<ll> &v) {
    ll now = 0;
    REP(i, v.size()) {
        ll nxt = v[i];
        bool exist = false;
        REP(j, V[now].node.size()) {
            if (V[now].node[j] == nxt)
                exist = true;
        }
        if (!exist)
            return false;
        now = nxt;
    }
    return true;
}

int main() {
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    vector<ll> v;
    REP(i, N - 1) {
        v.push_back(i + 1);
    }

    ll ans = 0;
    do {
        if (check(v))
            ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}