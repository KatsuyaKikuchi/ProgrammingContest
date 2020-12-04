#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 1e7 + 5;

pll A[500005];
ll P[MAX];

pll solve(ll n) {
    ll p = P[n];
    while (n % p == 0) {
        n /= p;
    }
    if (n == 1)
        return pll(-1, -1);
    return pll(p, n);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(P, 0, sizeof(P));
    FOR(i, MAX, 2) {
        if (P[i] > 0)
            continue;
        for (ll j = i; j < MAX; j += i) {
            if (P[j] == 0)
                P[j] = i;
        }
    }
    REP(i, N) {
        ll x;
        cin >> x;
        A[i] = solve(x);
    }

    REP(i, N) {
        cout << A[i].first << " ";
    }
    cout << endl;
    REP(i, N) {
        cout << A[i].second << " ";
    }
    cout << endl;
    return 0;
}