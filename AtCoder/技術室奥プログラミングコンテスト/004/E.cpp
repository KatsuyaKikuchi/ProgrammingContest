#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll B[200005];
ll A[200005];

int main() {
    ll N, M, K, E;
    cin >> N >> M >> K >> E;
    ll s = 0;
    REP(i, N) {
        cin >> A[i];
        s += A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }
    sort(B, B + M, [](ll a, ll b) { return a > b; });

    ll t = 0;
    REP(i, K) {
        t += B[i];
        if (t + E >= s) {
            cout << "Yes" << endl;
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    sort(A, A + N);
    ll e = E + t;
    REP(i, N) {
        e -= A[i];
        if (e < 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}