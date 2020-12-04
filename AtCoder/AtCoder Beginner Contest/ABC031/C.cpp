#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll max = -INF;
    REP(i, N) {
        //! iに丸をつける
        pll s(-INF, -INF);
        REP(j, N) {
            if (i == j)
                continue;
            ll as = 0, ts = 0;
            ll index = 0;
            REP(k, N) {
                if (k < std::min(i, j) || std::max(i, j) < k)
                    continue;
                if (index++ % 2 == 0)
                    ts += A[k];
                else
                    as += A[k];
            }
            if (s.second < as)
                s = pll(ts, as);
        }
        max = std::max(max, s.first);
    }
    cout << max << endl;
    return 0;
}