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
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> v(K);
    REP(i, K) {
        cin >> v[i];
    }

    REP(i, pow(2LL, N)) {
        bool e = true;
        REP(j, K) {
            if ((i & (1LL << v[j])) == 0)
                e = false;
        }
        if (!e)
            continue;
        cout << i << ":";
        REP(j, N) {
            if ((i >> j) & 1)
                cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}