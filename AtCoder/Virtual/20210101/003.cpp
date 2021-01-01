#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    ll n = 1;
    ll ans = 0;
    FOR(i, N, 1) {
        if (A[i] == A[i - 1]) {
            n++;
            while (n > A[i]) {
                ans++;
                n--;
            }
        }
        else {
            if (n < A[i - 1]) {
                ans += n;
            }
            n = 1;
        }
    }
    if (A[N - 1] > n) {
        ans += n;
    }
    cout << ans << endl;
    return 0;
}