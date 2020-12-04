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

    ll ai = 0, bi = 0;
    ll ans = 0;
    ll t = 0;
    while (true) {
        for (; ai < N; ++ai) {
            if (t <= A[ai]) {
                t = A[ai] + X;
                break;
            }
        }
        for (; bi < M; ++bi) {
            if (t <= B[bi]) {
                t = B[bi] + Y;
                break;
            }
        }

        if (ai >= N || bi >= M)
            break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}