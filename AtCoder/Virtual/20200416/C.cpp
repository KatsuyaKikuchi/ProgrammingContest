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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll r = 0, g = 0, b = 0;
    REP(i, N) {
        if (S[i] == 'R')
            r++;
        else if (S[i] == 'G')
            g++;
        else
            b++;
    }

    ll ans = r * g * b;
    FOR(i, N, 2) {
        REP(j, i) {
            ll d = i - j;
            if (j - d >= 0) {
                if (S[i] != S[j] && S[j] != S[j - d] && S[i] != S[j - d])
                    ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}