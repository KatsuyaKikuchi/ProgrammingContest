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
    string S, T;
    cin >> S >> T;
    if (S == T) {
        cout << "same" << endl;
        return 0;
    }
    REP(i, S.length()) {
        S[i] = toupper(S[i]);
        T[i] = toupper(T[i]);
    }
    if (S == T) {
        cout << "case-insensitive" << endl;
        return 0;
    }
    cout << "different" << endl;
    return 0;
}