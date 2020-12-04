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
ll B[200005];

vector<pll> V[2000005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }

    REP(i, N) {
        REP(j, M) {
            ll sum = A[i] + B[j];
            if (V[sum].size() > 0) {
                cout << V[sum][0].first << " " << V[sum][0].second << " " << i << " " << j << endl;
                return 0;
            }
            V[sum].push_back(pll(i, j));
        }
    }
    cout << -1 << endl;
    return 0;
}