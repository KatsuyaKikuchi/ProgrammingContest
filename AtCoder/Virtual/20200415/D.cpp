#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool P[100005];
ll S[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    memset(S, 0, sizeof(S));
    memset(P, 0, sizeof(P));
    P[0] = P[1] = true;
    for (ll i = 2; i <= 100002; ++i) {
        if (P[i])
            continue;
        for (ll j = 2 * i; j <= 100002; j += i) {
            P[j] = true;
        }
    }

    REP(i, 100002) {
        if (P[i])
            continue;
        if (P[(i + 1) / 2])
            continue;
        S[i]++;
    }

    REP(i, 100002) {
        S[i + 1] += S[i];
    }

    REP(i, N) {
        ll l, r;
        cin >> l >> r;
        cout << S[r] - S[l - 1] << endl;
    }
    return 0;
}