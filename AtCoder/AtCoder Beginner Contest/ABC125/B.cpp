#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[1000];
ll V[1000];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> V[i];
    }
    REP(i, N) {
        cin >> C[i];
    }

    ll max = 0;
    REP(p, pow(2LL, N )) {
        ll c = 0, v = 0;
        REP(i, N) {
            if (((p >> i) & 1) == 1) {
                c += C[i];
                v += V[i];
            }
        }
        max = std::max(max, v - c);
    }
    cout << max << endl;
    return 0;
}