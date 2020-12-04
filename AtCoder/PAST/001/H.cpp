#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[200005];

int main() {
    ll N;
    cin >> N;

    //! 全体最小値
    ll minAll = INF;
    //! 機数最小値
    ll minOdd = INF;
    REP(i, N) {
        cin >> C[i];
        minAll = std::min(minAll, C[i]);
        if (i % 2 == 0)
            minOdd = std::min(minOdd, C[i]);
    }
    ll Q;
    cin >> Q;

    //! 全体から引いた数
    ll allSum = 0;
    //! 帰趨番目から引いた数
    ll oddSum = 0;

    ll ans = 0;
    REP(q, Q) {
        ll t, a, x;
        cin >> t;
        if (t == 1) {
            cin >> x >> a;
            x--;
            ll d = 0;
            if (x % 2 == 0) {
                d = oddSum;
                ll e = std::max(0LL, C[x] - d);
                if (a > e)
                    continue;
                ans += a;
                C[x] -= a;
                minOdd = std::min(minOdd, C[x] - d);
                minAll = std::min(minAll, minOdd);
            }
            else {
                d = allSum;
                ll e = std::max(0LL, C[x] - d);
                if (a > e)
                    continue;
                ans += a;
                C[x] -= a;
                minAll = std::min(minAll, C[x] - d);
            }
        }
        else if (t == 2) {
            cin >> a;
            if (a > minOdd) {
                continue;
            }
            oddSum += a;
            ans += a * ((N + 1) / 2);
            minOdd = std::max(minOdd - a, 0LL);
            minAll = std::min(minAll, minOdd);
        }
        else if (t == 3) {
            cin >> a;
            if (a > minAll) {
                continue;
            }
            allSum += a;
            oddSum += a;
            ans += a * N;
            minAll = std::max(minAll - a, 0LL);
            minOdd -= a;
        }
    }

    cout << ans << endl;
    return 0;
}