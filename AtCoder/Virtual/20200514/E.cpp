#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool E[15][15];

bool check(vector<ll> &v) {
    ll index = 0;
    REP(i, v.size()) {
        ll nxt = v[i];
        if (!E[index][nxt])
            return false;
        index = nxt;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    memset(E, 0, sizeof(E));
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        E[a][b] = E[b][a] = true;
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