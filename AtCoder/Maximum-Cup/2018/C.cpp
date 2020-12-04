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
bool U[100005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
        A[i]--;
    }

    if (N % 2 == 1)
        cout << -1 << endl;
    else {
        memset(U, 0, sizeof(U));
        REP(i, N) {
            if (U[i])
                continue;
            ll n = 1;
            ll m = A[i];
            while (m != i) {
                n++;
                U[m] = true;
                m = A[m];
            }

            if (n % 2 == 1) {
                cout << -1 << endl;
                return 0;
            }
        }
        cout << N / 2 << endl;
    }
    return 0;
}