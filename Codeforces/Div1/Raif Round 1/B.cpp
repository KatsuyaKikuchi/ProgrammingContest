#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll ret = 0;
    ll T[2] = {0, 0};
    REP(i, N) {
        ll c0 = S[i];
        ll c1 = S[(i + 1) % N];
        if (c0 == '-' || c1 == '-')
            ret++;
        if (c0 == '>')
            T[0]++;
        if (c0 == '<')
            T[1]++;
    }

    if (T[0] == 0 || T[1] == 0)
        return N;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}