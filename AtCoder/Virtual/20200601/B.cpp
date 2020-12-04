#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(S, 0, sizeof(S));
    REP(i, N) {
        ll a;
        cin >> a;
        if (a >= 3200)
            a = 3200;
        S[a / 400]++;
    }

    ll p = S[8];
    ll a = 0;
    REP(i, 8) {
        if (S[i] > 0)
            a++;
    }
    cout << std::max(a, 1LL) << " " << a + p << endl;
    return 0;
}