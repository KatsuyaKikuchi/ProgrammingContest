#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string s = "atcoder";

bool check(string S, string T) {
    ll N = S.length();
    REP(i, N) {
        if (S[i] == T[i])
            continue;
        if (S[i] == '@' || T[i] == '@') {
            bool e = false;
            REP(j, s.length()) {
                if (s[j] == T[i] || s[j] == S[i])
                    e = true;
            }
            if (e)
                continue;
        }

        return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;

    if (check(S, T))
        cout << "You can win" << endl;
    else
        cout << "You will lose" << endl;
    return 0;
}