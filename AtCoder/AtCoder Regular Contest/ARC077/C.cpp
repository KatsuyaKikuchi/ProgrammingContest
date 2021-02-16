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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> B(N);
    ll idx = 0;
    for (ll i = N - 1; i >= 0; --i) {
        B[idx] = A[i];
        if ((N - 1 - i) % 2 == 0)
            idx = N - 1 - idx;
        else
            idx = N - idx;
    }
    REP(i, N) {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}