#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

int main() {
    ll N;
    cin >> N;
    ll S = 0;
    REP(i, N) {
        cin >> A[i];
        S += A[i];
    }
    for (ll i = N; i > 0; --i) {
        if (S % i != 0)
            continue;
        ll d = S / i;
        ll s = 0;
        REP(i, N) {
            s += A[i];
            if (s == d) {
                s = 0;
                continue;
            }
            else if (s > d)
                break;
        }
        if (s == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}