#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }
    ll cnt = 0;
    REP(j, N) {
        ll c = 0;
        REP(i, N) {
            if (S[i][j] == '#')
                c++;
        }
        if (c == N)
            cnt++;
    }

    vector<ll> count(N, 0);
    REP(i, N) {
        REP(j, N) {
            if (S[i][j] == '#')
                count[i]++;
        }
    }

    ll ans = INF;
    REP(i, N) {
        ll num = 0;
        REP(j, N) {
            if (S[i][j] == '#')
                continue;
            num++;
        }
        bool find = false;
        REP(j, N) {
            if (S[j][i] == '#') {
                find = true;
                break;
            }
        }
        if (!find) {
            ll min = INF;
            REP(j, N) {
                if (count[j] == 0)
                    continue;
                if (S[j][i] == '#' && S[i][i] == '.') {
                    min = std::min(min, num);
                }
                else {
                    min = std::min(min, num + 1);
                }
            }
            if (min < INF) {
                find = true;
                num = min;
            }
        }
        if (!find)
            continue;
        ans = std::min(num + N - cnt, ans);
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}