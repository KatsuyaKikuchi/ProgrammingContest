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
    string S;
    ll K;
    cin >> S >> K;
    REP(i, S.length()) {
        if (S[i] == '1')
            K--;
        if (K == 0 || S[i] != '1') {
            cout << S[i] << endl;
            break;
        }
    }
    return 0;
}