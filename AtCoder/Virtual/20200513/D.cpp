#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C0[30], C1[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    REP(i, N) {
        C0[S[i] - 'A']++;
    }
    REP(i, M) {
        C1[T[i] - 'A']++;
    }

    ll ans = 0;
    REP(i, 27) {
        if (C0[i] > 0 && C1[i] == 0) {
            ans = -1;
            break;
        }
        if (C1[i] == 0)
            continue;
        ans = std::max(ans, (C0[i] + C1[i] - 1) / C1[i]);
    }
    cout << ans << endl;
    return 0;
}