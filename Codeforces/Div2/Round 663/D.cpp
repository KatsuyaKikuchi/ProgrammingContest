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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    if (N >= 4) {
        cout << -1 << endl;
        return 0;
    }
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (N == 2) {
        ll ans = 0;
        {
            vector<string> v = S;
            ll m = 0;
            REP(i, M - 1) {
                ll n = v[0][i] + v[0][i + 1] + v[1][i] + v[1][i + 1] - (4 * '0');
                if (n % 2 == 0) {
                    v[0][i + 1] = (char) ((v[0][i + 1] - '0' + 1) % 2 + '0');
                    m++;
                }
            }
            ans = std::min(ans, m);
        }
        {
            ll m = 0;
            vector<string> v = S;
            for (ll i = M - 1; i >= 1; --i) {
                ll n = v[0][i] + v[0][i - 1] + v[1][i] + v[1][i - 1] - (4 * '0');
                if (n % 2 == 0) {
                    v[0][i] = (char) ((v[0][i - 1] - '0' + 1) % 2 + '0');
                    m++;
                }
            }
            ans = std::min(ans, m);
        }
        cout << ans << endl;
        return 0;
    }
    {
        ll ans = INF;
        {
            ll m = 0;
            vector<string> v = S;
            REP(i, M - 1) {
                pll x(0, 0);
                x.first = v[0][i] + v[0][i + 1] + v[1][i] + v[1][i + 1] - (4 * '0');
                x.second = v[2][i] + v[2][i + 1] + v[1][i] + v[1][i + 1] - (4 * '0');

                if (x.first % 2 == 1 && x.second % 2 == 1)
                    continue;
                m++;
                if (x.first % 2 == 0 && x.second % 2 == 0) {
                    v[1][i + 1] = (char) ((v[1][i + 1] - '0' + 1) % 2 + '0');
                }
                else if (x.first % 2 == 0) {
                    v[0][i + 1] = (char) ((v[0][i + 1] - '0' + 1) % 2 + '0');
                }
                else if (x.second % 2 == 0) {
                    v[2][i + 1] = (char) ((v[2][i + 1] - '0' + 1) % 2 + '0');
                }
            }
            ans = std::min(ans, m);
        }
        {
            ll m = 0;
            vector<string> v = S;
            for (ll i = M - 1; i >= 1; --i) {
                pll x(0, 0);
                x.first = v[0][i] + v[0][i - 1] + v[1][i] + v[1][i - 1] - (4 * '0');
                x.second = v[2][i] + v[2][i - 1] + v[1][i] + v[1][i - 1] - (4 * '0');

                if (x.first % 2 == 1 && x.second % 2 == 1)
                    continue;
                m++;
                if (x.first % 2 == 0 && x.second % 2 == 0) {
                    v[1][i - 1] = (char) ((v[1][i - 1] - '0' + 1) % 2 + '0');
                }
                else if (x.first % 2 == 0) {
                    v[0][i - 1] = (char) ((v[0][i - 1] - '0' + 1) % 2 + '0');
                }
                else if (x.second % 2 == 0) {
                    v[2][i - 1] = (char) ((v[2][i - 1] - '0' + 1) % 2 + '0');
                }
            }
            ans = std::min(ans, m);
        }
        cout << ans << endl;
    }
    return 0;
}