#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve() {
    string S;
    cin >> S;
    ll one = 0;
    ll zero = 0;
    ll N = S.length();
    REP(i, N) {
        if (S[i] == '0')
            zero++;
        if (S[i] == '1')
            one++;
    }

    string ret = "";
    if (zero == 0) {
        return S;
    }
    else if (one == 0) {
        return S;
    }
    else {
        char c0 = S[0];
        char c1 = c0 == '0' ? '1' : '0';
        REP(i, N) {
            ret.push_back(c0);
            ret.push_back(c1);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}