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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    pll mx(0, 2);
    FOR(i, 1005, 2) {
        ll n = 0;
        REP(j, N) {
            if (A[j] % i == 0)
                n++;
        }
        if (mx.first < n) {
            mx = pll(n, i);
        }
    }
    cout << mx.second << endl;
    return 0;
}