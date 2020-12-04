#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    string S;
    cin >> S;
    ll z = 0, o = 0;
    REP(i, S.length()) {
        if (S[i] == '0')
            z++;
        else
            o++;
    }

    if (std::min(z, o) % 2 == 0)
        return false;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "DA" << endl;
        else
            cout << "NET" << endl;
    }
    return 0;
}