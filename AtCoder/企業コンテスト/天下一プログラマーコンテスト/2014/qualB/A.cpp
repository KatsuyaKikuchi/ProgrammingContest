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
    string s = "";
    REP(i, S.length()) {
        string t = "";
        REP(j, 6) {
            t.push_back(S[i + j]);
        }
        if (t != "HAGIYA") {
            s.push_back(S[i]);
            continue;
        }
        s += "HAGIXILE";
        FOR(j, S.length(), i + 6) {
            s.push_back(S[j]);
        }
        break;
    }
    cout << s << endl;
    return 0;
}