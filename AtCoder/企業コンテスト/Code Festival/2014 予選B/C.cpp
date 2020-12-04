#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[3];
ll C[3][30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 3) {
        cin >> S[i];
    }
    ll N = S[0].length() / 2;
    memset(C, 0, sizeof(C));
    REP(i, 2 * N) {
        REP(j, 3) {
            ll n = S[j][i] - 'A';
            C[j][n]++;
        }
    }

    ll a = 0, b = 0;
    REP(i, 30) {
        ll x = C[0][i], y = C[1][i], z = C[2][i];
        a += std::max(0LL, z - y);
        b += std::max(0LL, z - x);
    }

    if (a > N || b > N)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;


    return 0;
}