#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N, 1);
    for (ll i = 1; i <= N; ++i) {
        ll x = A[i - 1];
        for (ll j = 2 * i; j <= N; j += i) {
            A[j - 1] = std::max(A[j - 1], x + 1);
        }
    }
    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}