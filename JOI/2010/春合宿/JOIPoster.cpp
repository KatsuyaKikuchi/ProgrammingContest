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
    if (N == 0) {
        cout << "J" << endl;
        return 0;
    }
    ll p = pow(2, N);
    string s = "";
    while (p > 1) {
        ll q = p / 2;
        if (K <= q) {
            REP(i, q) {
                s.push_back('J');
            }
            REP(i, q) {
                s.push_back('O');
            }
            break;
        }
        REP(i, q) {
            s.push_back('I');
        }
        K -= q;
        p /= 2;
        if (p == 1)
            s.push_back('J');
    }

    cout << s << endl;
    return 0;
}