#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }
    ll ans = 0;
    REP(i, 9) {
        bool b = false;
        REP(j, N) {
            if (S[j][i] == 'o') {
                if (!b)
                    ans++;
                b = true;
            }
            else {
                b = false;
            }
            if (S[j][i] == 'x') {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}