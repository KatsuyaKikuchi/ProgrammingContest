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
    sort(A.begin(), A.end());
    vector<ll> B(N);
    ll index = 0;
    ll t = 1;
    while (t < N) {
        B[t] = A[index++];
        t += 2;
    }
    t = 0;
    while (t < N) {
        B[t] = A[index++];
        t += 2;
    }
    ll ans = 0;
    FOR(i, N - 1, 1) {
        if (B[i - 1] > B[i] && B[i] < B[i + 1])
            ans++;
    }
    cout << ans << endl;
    REP(i, N) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}