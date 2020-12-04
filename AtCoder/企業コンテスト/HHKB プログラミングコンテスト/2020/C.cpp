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
bool U[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(U, 0, sizeof(U));
    REP(i, N) {
        cin >> A[i];
    }

    ll n = 0;
    REP(i, N) {
        U[A[i]] = true;
        while (U[n]) {
            n++;
        }
        cout << n << endl;
    }
    return 0;
}