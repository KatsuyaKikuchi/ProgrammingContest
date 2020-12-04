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
    ll N;
    cin >> N;
    string S;
    cin >> S;

    string ret = "";
    REP(i, N) {
        if (S[i] == '1')
            break;
        ret.push_back('0');
    }
    string suf = "";
    for (ll i = N - 1; i >= 0; --i) {
        if (S[i] == '0')
            break;
        suf.push_back('1');
    }
    if (suf.length() + ret.length() < N)
        ret.push_back('0');
    return ret + suf;
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