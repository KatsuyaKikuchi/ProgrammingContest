#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<vector<ll>> V;
vector<ll> odd, even;

void dfs(ll idx, ll parent, ll dst) {
    if (dst % 2 == 0)
        even.push_back(idx);
    else
        odd.push_back(idx);
    for (auto nxt:V[idx]) {
        if (nxt == parent)
            continue;
        dfs(nxt, idx, dst + 1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    V.resize(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    dfs(0,-1,0);
    if (even.size() > odd.size())
        swap(odd, even);
    REP(i, N / 2) {
        cout << odd[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}