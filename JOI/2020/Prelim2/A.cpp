#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[505];
string T[505];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }
    REP(i, N) {
        cin >> T[i];
    }

    ll ans = INF;
    {
        //! そのまま
        ll m = 0;
        REP(i, N) {
            REP(j, N) {
                if (S[i][j] != T[i][j])
                    m++;
            }
        }
        ans = std::min(ans, m);
    }
    {
        //! 右90
        ll m = 1;
        REP(i, N) {
            REP(j, N) {
                if (S[N - 1 - j][i] != T[i][j])
                    m++;
            }
        }
        ans = std::min(ans, m);
    }
    {
        //! 左90
        ll m = 1;
        REP(i, N) {
            REP(j, N) {
                if (S[j][N - 1 - i] != T[i][j])
                    m++;
            }
        }
        ans = std::min(ans, m);
    }
    {
        //! 180
        ll m = 2;
        REP(i, N) {
            REP(j, N) {
                if (S[N - 1 - i][N - 1 - j] != T[i][j])
                    m++;
            }
        }
        ans = std::min(ans, m);
    }
    cout << ans << endl;
    return 0;
}