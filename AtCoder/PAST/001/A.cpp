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
    string S;
    cin >> S;
    ll n = 0;
    REP(i, 3) {
        if (S[i] > '9' || S[i] < '0') {
            cout << "error" << endl;
            return 0;
        }
        n = n * 10 + S[i] - '0';
    }
    cout << n * 2 << endl;
    return 0;
}