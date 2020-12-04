#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[10];

ll solve(vector<string> s) {
    ll n = 0;
    REP(i, 5) {
        REP(j, s[i].length()) {
            if (s[i][j] == '.')
                n++;
        }
    }
    if (n == 7)
        return 1;
    if (n == 6)
        return 4;
    if (n == 8)
        return 7;
    if (n == 2)
        return 8;
    if (n == 3) {
        if (s[1][2] == '.')
            return 6;
        if (s[3][0] == '.')
            return 9;
        return 0;
    }

    if (s[1][0] == '#')
        return 5;
    if (s[3][2] == '.')
        return 2;
    return 3;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, 5) {
        cin >> S[i];
    }

    string T = "";
    REP(i, N) {
        vector<string> s(5);
        REP(j, 5) {
            string t = "";
            REP(k, 3) {
                t.push_back(S[j][4 * i + 1 + k]);
            }
            s[j] = t;
        }
        ll n = solve(s);
        T.push_back((char) (n + '0'));
    }
    cout << T << endl;
    return 0;
}