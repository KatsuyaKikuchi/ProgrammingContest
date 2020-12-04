#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve(string &S) {
    string T = "";
    ll d = 0;
    REP(i, S.length()) {
        ll n = S[i] - '0';
        if (n > d) {
            while (n != d) {
                d++;
                T.push_back('(');
            }
        }
        else if (n < d) {
            while (n != d) {
                d--;
                T.push_back(')');
            }
        }
        T.push_back(S[i]);
    }

    while (d > 0) {
        d--;
        T.push_back(')');
    }
    return T;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(q, Q) {
        string S;
        cin >> S;
        cout << "Case #" << q + 1 << ": ";
        cout << solve(S) << endl;
    }
    return 0;
}