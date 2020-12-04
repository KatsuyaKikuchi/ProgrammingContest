#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll X[20];
ll A[20];
bool U[20];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        ll x = 0;
        REP(j, N) {
            ll a;
            cin >> a;
            x |= (a << j);
        }
        X[i] = x;
    }

    REP(i, N) {
        cin >> A[i];
    }

    ll ans = INF;
    ll p = pow(2, N);
    REP(i, p) {
        ll x = i;
        memset(U, 0, sizeof(U));
        ll num = 0;
        while (true) {
            bool exist = false;
            REP(j, N) {
                if (U[j])
                    continue;
                if ((X[j] & x) == X[j]) {
                    exist = true;
                    x |= (1LL << j);
                    num++;
                    U[j] = true;
                }
            }
            if (!exist)
                break;
        }
        if (num < N)
            continue;
        ll m = 0;
        REP(j, N) {
            if (((i >> j) & 1) == 1)
                m += A[j];
        }
        ans = std::min(ans, m);
    }
    cout << ans << endl;
    return 0;
}