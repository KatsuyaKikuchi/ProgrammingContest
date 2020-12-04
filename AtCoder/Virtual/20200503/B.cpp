#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[55];
pll B[55];
ll C[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    REP(i, M) {
        cin >> B[i].first >> B[i].second;
    }

    REP(i, N) {
        ll n = 0;
        REP(j, M) {
            ll d0 = abs(A[i].first - B[j].first) + abs(A[i].second - B[j].second);
            ll d1 = abs(A[i].first - B[n].first) + abs(A[i].second - B[n].second);
            if (d0 < d1)
                n = j;
        }
        C[i] = n + 1;
    }

    REP(i, N) {
        cout << C[i] << endl;
    }

    return 0;
}