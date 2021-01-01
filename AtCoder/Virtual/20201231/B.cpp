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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    ll ans = 0;
    ll left = 0;
    ll cnt = 0;
    REP(i, N) {
        if (S[i] == '0') {
            if ((i > 0 && S[i - 1] == '1') || i == 0)
                cnt++;
            while (cnt > K) {
                left++;
                if (S[left] == '1' && S[left - 1] == '0')
                    cnt--;
            }
        }
        ans = std::max(ans, i - left + 1);
    }
    cout << ans << endl;
    return 0;
}