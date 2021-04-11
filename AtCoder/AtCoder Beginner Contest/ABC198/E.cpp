#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[100005];
vector<ll> V[100005];
vector<ll> ans;
bool U[100005];

void dfs(ll index, ll parent = -1) {
    ll c = C[index];
    if (!U[c])
        ans.push_back(index);

    bool t = U[c];
    U[c] = true;
    REP(i, V[index].size()) {
        ll nxt = V[index][i];
        if (nxt == parent)
            continue;
        dfs(nxt, index);
    }
    if (!t)
        U[c] = false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(U, 0, sizeof(U));
    REP(i, N) {
        cin >> C[i];
    }
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    dfs(0);
    sort(ans.begin(), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}