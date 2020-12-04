#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string s = "keyence";

int main() {
    string S;
    cin >> S;
    ll N = S.length();
    bool exist = S == s;
    REP(i, N) {
        FOR(j, N, i) {
            ll index = 0;
            bool e = true;
            REP(n, N) {
                if (n >= i && n <= j)
                    continue;

                if (index >= s.length()) {
                    e = false;
                    break;
                }
                if (s[index] != S[n]) {
                    e = false;
                    break;
                }
                index++;
            }
            if (e && index == s.length())
                exist = true;
        }
    }

    if (exist)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}