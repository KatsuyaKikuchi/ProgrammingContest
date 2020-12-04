#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, K;
ll W[100005];

bool check(ll p) {

    ll s = 0;
    ll k = 1;
    REP(i, N) {
        if (p < W[i])
            return false;
        if (s + W[i] > p) {
            k++;
            s = 0;
        }
        s += W[i];
    }

    return k <= K;
}

int main() {
    cin >> N >> K;
    REP(i, N) {
        cin >> W[i];
    }

    ll ok = INF, ng = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}