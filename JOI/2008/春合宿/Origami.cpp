#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll L[5005], R[5005];
ll S[25][25];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, B;
    cin >> N >> A >> B;
    REP(i, N) {
        cin >> L[i].first >> L[i].second;
        cin >> R[i].first >> R[i].second;
    }

    ll max = 0;
    ll s = 0;
    REP(i, N) {
        memset(S, 0, sizeof(S));

        FOR(j, N, i + 1) {
            pll tl = pll(std::max(L[i].first, L[j].first), std::max(L[i].second, L[j].second));
            pll tr = pll(std::min(R[i].first, R[j].first), std::min(R[i].second, R[j].second));

            ll l = tl.first - L[i].first, r = tr.first - L[i].first;
            ll u = tl.second - L[i].second, t = tr.second - L[i].second;
            if (l > r || u > t)
                continue;
            S[l][u]++;
            S[l][t + 1]--;
            S[r + 1][u]--;
            S[r + 1][t + 1]++;
        }

        REP(x, R[i].first - L[i].first + 1) {
            REP(y, R[i].second - L[i].second + 1) {
                S[x][y + 1] += S[x][y];
            }
        }
        REP(y, R[i].second - L[i].second + 1) {
            REP(x, R[i].first - L[i].first + 1) {
                S[x + 1][y] += S[x][y];
            }
        }
        ll m = 0;
        REP(x, R[i].first - L[i].first + 1) {
            REP(y, R[i].second - L[i].second + 1) {
                m = std::max(m, S[x][y]);
            }
        }
        if (m > max) {
            max = m;
            s = 0;
        }
        REP(x, R[i].first - L[i].first + 1) {
            REP(y, R[i].second - L[i].second + 1) {
                if (S[x][y] == max)
                    s++;
            }
        }
    }
    cout << max + 1 << endl;
    cout << s << endl;
    return 0;
}