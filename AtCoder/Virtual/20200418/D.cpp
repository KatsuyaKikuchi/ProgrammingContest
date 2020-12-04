#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll sum(ll N) {
    ll n = N % 4;
    if (n == 1)
        return 1;
    if (n == 3)
        return 0;
    if (n == 2)
        return 3LL + 4LL * (N - 2) / 4;
    return N;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B;
    cin >> A >> B;

    cout << (sum(B) ^ sum(std::max(A - 1, 0LL))) << endl;
    return 0;
}