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
    string S;
    cin >> S;
    ll N = S.length();

    ll ans = 0;
    ll n = 0;
    ll index = 0;
    while (index < N - 1) {
        if (S[index] == '2' && S[index + 1] == '5') {
            n++;
            ans += n;
            index += 2;
            continue;
        }
        n = 0;
        index++;
    }
    cout << ans << endl;
    return 0;
}