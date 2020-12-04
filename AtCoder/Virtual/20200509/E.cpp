#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    memset(S, 0, sizeof(S));
    vector<pll> e;
    REP(i, N - 1) {
        e.push_back(pll(1, i + 2));
    }
    K -= (N - 2) * (N - 1) / 2;
    if (K > 0) {
        cout << -1 << endl;
        return 0;
    }
    ll left = 2;
    ll right = 3;
    while (K++ < 0) {
        e.push_back(pll(left, right++));
        if (right > N) {
            left++;
            right = left + 1;
        }
    }

    cout << e.size() << endl;
    REP(i, e.size()) {
        cout << e[i].first << " " << e[i].second << endl;
    }
    return 0;
}