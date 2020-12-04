#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;

    REP(i, pow(2, 3)) {
        ll sum = S[0] - '0';
        REP(j, 3) {
            ll m = S[j + 1] - '0';
            if ((i >> j) & 1)
                sum += m;
            else
                sum -= m;
        }
        if (sum != 7)
            continue;

        string s = "";
        s.push_back(S[0]);
        REP(j, 3) {
            if ((i >> j) & 1)
                s.push_back('+');
            else
                s.push_back('-');
            s.push_back(S[j + 1]);
        }

        s += "=7";
        cout << s << endl;
        break;
    }
    return 0;
}