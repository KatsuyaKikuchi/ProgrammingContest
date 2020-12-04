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
ll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    ll X, Y;
    cin >> X >> Y;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }
    ll ans = 0;
    ll t = 0;
    ll ai = 0, bi = 0;
    while (ai < N && bi < M) {
        while (ai < N && A[ai] < t)
            ai++;
        if (ai >= N)
            break;
        t = A[ai] + X;
        while (bi < M && B[bi] < t)
            bi++;
        if (bi >= M)
            break;
        t = B[bi] + Y;
        ans++;
    }
    cout << ans << endl;
    return 0;
}