#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[105];
pll B[20];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
    }
    ll K;
    cin >> K;
    REP(i, K) {
        cin >> B[i].first >> B[i].second;
    }
    ll ans = 0;
    REP(bit, pow(2LL, K)) {
        vector<bool> S(N, false);
        REP(i, K) {
            if ((bit >> i) & 1)
                S[B[i].second - 1] = true;
            else
                S[B[i].first - 1] = true;
        }
        ll cnt = 0;
        REP(i, M) {
            if (S[A[i].first - 1] && S[A[i].second - 1])
                cnt++;
        }
        ans = std::max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}