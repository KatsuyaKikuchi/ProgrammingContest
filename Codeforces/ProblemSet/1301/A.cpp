#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve(string &A, string &B, string &C) {
    ll n = A.length();
    REP(i, n) {
        if (A[i] == C[i] || B[i] == C[i])
            continue;
        return "NO";
    }
    return "YES";
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        string A, B, C;
        cin >> A >> B >> C;
        cout << solve(A, B, C) << endl;
    }
    return 0;
}