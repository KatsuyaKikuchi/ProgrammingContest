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
    string S, T;
    cin >> S >> T;
    ll N = S.length();
    ll ans = INF;
    if (S.length() == T.length()) {
        for (ll i = N - 1; i >= 0; --i) {
            bool e = true;
            REP(j, N) {
                if (S[(i + j) % N] != T[j])
                    e = false;
            }
            if (e)
                ans = std::min(ans, (N - i) % N);
        }
    }

    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}