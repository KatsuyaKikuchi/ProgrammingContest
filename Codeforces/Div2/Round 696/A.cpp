#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll p = 0;
    string ret = "";
    REP(i, N) {
        ll a = S[i] - '0';
        if (a + 1 == p) {
            ret.push_back('0');
            p = a;
        }
        else {
            ret.push_back('1');
            p = a + 1;
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