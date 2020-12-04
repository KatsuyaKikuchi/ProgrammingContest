#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M;
ll X, K, Y;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cin >> X >> K >> Y;
    vector<ll> A(N), B(M + 2);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i + 1];
    }
    B[0] = -1;
    B[M + 1] = INF;
    A.push_back(INF);

    ll ans = 0;
    ll index = 1;
    ll mx = -1;
    ll si = 0;
    REP(i, N + 1) {
        if (B[index] != A[i]) {
            mx = std::max(mx, A[i]);
            continue;
        }

        ll n = i - si;
        if ((mx > B[index] && mx > B[index - 1]) ||
            (B[index] == INF && mx > B[index - 1])) {
            ans += X;
            n -= K;
        }

        if (n < 0) {
            index = -1;
            break;
        }

        ans += std::min((n % K) * Y + (n / K) * X, n * Y);
        index++;
        si = i + 1;
        mx = -1;
    }

    if (index < M)
        ans = -1;
    cout << ans << endl;
    return 0;
}