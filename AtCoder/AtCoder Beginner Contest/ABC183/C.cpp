#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, K;
ll T[10][10];

ll solve(vector<ll> v) {
    ll ret = T[0][v[0]];
    REP(i, v.size() - 1) {
        ret += T[v[i]][v[i + 1]];
    }
    ret += T[v[v.size() - 1]][0];
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    REP(i, N) {
        REP(j, N) {
            cin >> T[i][j];
        }
    }

    vector<ll> v;
    REP(i, N - 1) {
        v.push_back(i + 1);
    }

    ll ans = 0;
    do {
        if (solve(v) == K)
            ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}