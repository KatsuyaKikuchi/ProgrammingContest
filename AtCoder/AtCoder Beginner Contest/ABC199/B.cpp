#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105];
ll B[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    ll ans = 0;
    REP(x, 1005) {
        bool e = true;
        REP(i, N) {
            if (A[i] <= x && x <= B[i])
                continue;
            e = false;
            break;
        }
        if (e)
            ans++;
    }
    cout << ans << endl;
    return 0;
}