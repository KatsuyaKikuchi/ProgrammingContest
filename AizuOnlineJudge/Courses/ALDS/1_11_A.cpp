#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<vector<ll>> edge(N, vector<ll>(N, 0));
    REP(_, N) {
        ll n, k;
        cin >> n >> k;
        n--;
        REP(__, k) {
            ll v;
            cin >> v;
            v--;
            edge[n][v]++;
        }
    }

    REP(i, N) {
        REP(j, N) {
            cout << edge[i][j];
            if (j < N - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}