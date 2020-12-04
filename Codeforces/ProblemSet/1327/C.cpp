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
    ll N, M, K;
    cin >> N >> M >> K;
    REP(i, K) {
        ll s, t;
        cin >> s >> t;
    }
    REP(i, K) {
        ll s, t;
        cin >> s >> t;
    }

    string ret = "";
    REP(i, N - 1) {
        ret.push_back('U');
    }
    REP(i, M - 1) {
        ret.push_back('L');
    }

    REP(i, N) {
        REP(j, M - 1) {
            if (i % 2 == 0)
                ret.push_back('R');
            else
                ret.push_back('L');
        }
        ret.push_back('D');
    }

    cout << ret.size() << endl;
    cout << ret << endl;
    return 0;
}