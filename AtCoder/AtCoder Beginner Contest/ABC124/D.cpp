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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    ll l = 0;
    ll t = 0;
    ll max = 0;
    REP(i, N) {
        if (S[i] - '0' == 0) {
            if (i == 0 || S[i - 1] == '1') {
                t++;
            }
        }
        if (t > K) {
            for (ll j = l + 1; j <= i; ++j) {
                if (S[j] == '1' && S[j - 1] == '0') {
                    t--;
                    l = j;
                    break;
                }
            }
        }
        max = std::max(max, i - l + 1);
    }
    cout << max << endl;
    return 0;
}