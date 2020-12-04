#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string A[105];
string B[105];

int main() {
    ll N, M;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    cin >> M;
    REP(i, M) {
        cin >> B[i];
    }

    ll ans = 0;
    REP(i, N) {
        ll s = 0;
        REP(j, N) {
            if (A[i] == A[j])
                s++;
        }
        REP(j, M) {
            if (B[j] == A[i])
                s--;
        }
        ans = std::max(ans, s);
    }
    cout << ans << endl;
    return 0;
}