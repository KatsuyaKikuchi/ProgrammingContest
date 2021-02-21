#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    memset(C, 0, sizeof(C));
    ll ans = 0;
    C[S[N - 1] - 'a']++;
    for (ll i = N - 2; i >= 1; --i) {
        if (S[i] != S[i - 1]) {
            C[S[i] - 'a']++;
            continue;
        }

        ans += N - (i + 1) - C[S[i] - 'a'];

        memset(C, 0, sizeof(C));
        C[S[i] - 'a'] += N - i;
    }
    cout << ans << endl;
    return 0;
}