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
    ll N, A, B;
    cin >> N >> A >> B;
    if (A > B || (A != B && N == 1)) {
        cout << 0 << endl;
        return 0;
    }

    ll min = A * (N - 1) + B;
    ll max = A + B * (N - 1);
    cout << max - min + 1LL << endl;
    return 0;
}