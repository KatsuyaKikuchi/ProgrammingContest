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
    string S;
    cin >> S;
    ll N = S.length();
    ll left = 0, right = N - 1;
    ll ans = 0;
    while (left < right) {
        if (S[left] == S[right]) {
            left++;
            right--;
            continue;
        }
        if (S[left] == 'x') {
            ans++;
            left++;
        }
        else if (S[right] == 'x') {
            ans++;
            right--;
        }
        else {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}