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
    ll N;
    string S;
    cin >> N >> S;
    ll ans = 0;
    REP(i, 1000) {
        ll index = 0;
        ll T[3] = {i / 100, (i % 100) / 10, (i % 10)};
        REP(n, N) {
            if (S[n] - '0' == T[index])
                index++;

            if (index == 3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}