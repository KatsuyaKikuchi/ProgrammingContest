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
ll C[100005];
ll D[100005];
ll P[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    memset(C, 0, sizeof(C));
    memset(P, 0, sizeof(P));
    REP(i, N) {
        cin >> A[i];
        C[A[i]]++;
        D[A[i] % M]++;
    }
    REP(i, 100005) {
        P[i % M] += C[i] / 2;
    }
    ll ans = 0;
    REP(i, M) {
        ll d = (M - i) % M;
        if (d != i) {
            ll m = std::min(D[d], D[i]);
            ans += m;
            D[d] -= m;
            D[i] -= m;
            ll x = std::min(P[d], D[d] / 2);
            ll y = std::min(P[i], D[i] / 2);
            ans += x + y;
            P[d] -= x;
            D[d] -= 2 * x;
            P[i] -= y;
            D[i] -= 2 * y;
        }
        else {
            ll m = D[i] / 2;
            ans += m;
            D[i] -= 2 * m;
            ll x = std::min(P[i], D[i] / 2);
            ans += x;
            P[i] -= x;
            D[i] -= 2 * x;
        }
    }
    cout << ans << endl;
    return 0;
}