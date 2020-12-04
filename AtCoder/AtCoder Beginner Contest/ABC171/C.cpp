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
    ll index = 1;
    ll m = 1;
    ll sum = 0;
    while (true) {
        if (index * 26LL >= N) {
            string s = "";
            REP(_, m) {
                REP(i, 26) {
                    if (N - index <= 0) {
                        s.push_back((char) ('a' + i));
                        index /= 26LL;
                        break;
                    }
                    N -= index;
                }
            }
            cout << s << endl;
            break;
        }

        index *= 26LL;
        N -= index;
        m++;
    }
    return 0;
}