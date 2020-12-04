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
    ll N, L;
    cin >> N >> L;

    ll s = 0;

    REP(i, N) {
        s += L + i;
    }

    if (L > 0) {
        s -= L;
    }
    else if (L + N - 1 >= 0) {

    }
    else {
        s -= L + N - 1;
    }


    cout << s << endl;
    return 0;
}