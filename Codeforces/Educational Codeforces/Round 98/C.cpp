#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    string S;
    cin >> S;
    ll N = S.length();
    ll ret = 0;
    stack<ll> s, t;
    REP(i, N) {
        if (S[i] == '(')
            s.push(i);
        else if (S[i] == '[')
            t.push(i);
        else if (S[i] == ')') {
            if (!s.empty()) {
                ret++;
                s.pop();
            }
        }
        else {
            if (!t.empty()) {
                t.pop();
                ret++;
            }
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