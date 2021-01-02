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
    ll ans = 0;
    ll left = 0, right = N - 1;
    ll ls = 0, rs = 0;
    while (left < right) {
        ll l = 2 * (ls + A[left]) + A[left + 1] + 1;
        ll r = 2 * (rs + A[right]) + A[right - 1] + 1;
        if (l < r) {
            ans += l;
            ls = ls + A[left] + A[left + 1] + 2;
            left += 2;
        }
        else {
            ans += r;
            rs = rs + A[right] + A[right - 1] + 2;
            right -= 2;
        }
        //cout << ls << " " << rs << endl;
    }
    cout << ans << endl;
    return 0;
}