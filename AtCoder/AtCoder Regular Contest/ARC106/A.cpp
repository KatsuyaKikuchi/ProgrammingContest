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
    ll a = 1;
    ll A = 3;
    while (true) {
        ll b = 1;
        ll B = 5;
        if (A > N)
            break;
        while (true) {
            if (A + B > N)
                break;
            if (A + B == N) {
                cout << a << " " << b << endl;
                return 0;
            }
            b++;
            B = B * 5LL;
        }
        a++;
        A = A * 3LL;
    }
    cout << -1 << endl;
    return 0;
}