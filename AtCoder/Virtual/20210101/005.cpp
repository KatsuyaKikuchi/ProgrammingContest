#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string s = "atcoder@";

bool solve() {
    string S, T;
    cin >> S >> T;
    if (S.length() != T.length())
        return false;

    ll N = S.length();
    REP(i, N) {
        if (S[i] == '@') {
            bool e = false;
            REP(j, s.length()) {
                if (T[i] == s[j])
                    e = true;
            }
            if (!e)
                return false;
        }
        else if (T[i] == '@') {
            bool e = false;
            REP(j, s.length()) {
                if (S[i] == s[j])
                    e = true;
            }
            if (!e)
                return false;
        }
        else if (S[i] != T[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    if (solve())
        cout << "You can win" << endl;
    else
        cout << "You will lose" << endl;
    return 0;
}