#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, R;
    cin >> N >> R;
    string S;
    cin >> S;

    ll ans = 0;
    for (ll i = N - 1; i >= 0; --i) {
        if (S[i] == 'o')
            continue;
        ans = std::max(0LL, i - R + 1);
        REP(j, i + 1) {
            if (S[j] == 'o')
                continue;
            ans++;
            REP(k, R) {
                if (j + k >= N)
                    break;
                S[j + k] = 'o';
            }
        }
        break;
    }
    cout << ans << endl;
    return 0;
}