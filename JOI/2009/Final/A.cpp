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
    ll N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    ll ans = 0;
    ll p = 1;
    FOR(i, M, 1) {
        if (S[i] == S[i - 1])
            p = 0;
        ++p;
        if (S[i] == 'I' && ((p - 1) / 2) >= N)
            ans++;
    }
    cout << ans << endl;
    return 0;
}