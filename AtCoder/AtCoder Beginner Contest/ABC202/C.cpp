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
    cin>>N;

    vector<ll> A(N), B(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    vector<ll> T(N + 1, 0);
    REP(i, N) {
        ll c;
        cin >> c;
        c--;
        T[B[c]]++;
    }
    ll ans = 0;
    REP(i, N) {
        ans += T[A[i]];
    }
    cout << ans << endl;
    return 0;
}