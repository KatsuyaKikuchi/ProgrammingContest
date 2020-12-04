#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, H, W;
pll A[55];

bool check(pll a, pll b, pll c, pll d) {
    ll lasq = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    ll lcsq = (c.first - d.first) * (c.first - d.first) + (c.second - d.second) * (c.second - d.second);

    if (lasq > a.first * a.first || lasq > (H - a.first) * (H - a.first) ||
        lasq > a.second * a.second || lasq > (W - a.second) * (W - a.second))
        return false;
    if (lcsq > c.first * c.first || lcsq > (H - c.first) * (H - c.first) ||
        lcsq > c.second * c.second || lcsq > (W - c.second) * (W - c.second))
        return false;

    ll difsq = (a.first - c.first) * (a.first - c.first) + (a.second - c.second) * (a.second - c.second);

    ll t = lasq - (lcsq + difsq);
    if (t < 0)
        return false;

    if (4LL * lcsq * difsq < t * t)
        return true;

    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> W >> H;
    REP(i, N) {
        cin >> A[i].second >> A[i].first;;
    }

    ll ans = 0;
    REP(a, N) {
        REP(b, N) {
            if (a == b)
                continue;
            REP(c, N) {
                if (a == c || b == c)
                    continue;
                REP(d, N) {
                    if (d == a || d == b || d == c)
                        continue;
                    if (check(A[a], A[b], A[c], A[d]))
                        ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}