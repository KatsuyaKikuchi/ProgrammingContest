#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char L[8] = {'(', '{', '[', ')', '}', ']', 'i', 'w'};
char R[8] = {')', '}', ']', '(', '{', '[', 'i', 'w'};

ll T[20];

int main() {
    string S;
    cin >> S;
    ll N = S.length();
    ll ans = 3;
    REP(i, pow(2LL, N)) {
        string s = "";
        REP(j, N) {
            if ((i >> j) & 1)
                s.push_back(S[j]);
        }

        ll n = s.length();
        bool e = false;
        REP(i, n - 2) {
            if (s[i] == 'i' && s[i + 1] == 'w' && s[i + 2] == 'i')
                e = true;
        }
        REP(i, n) {
            ll a = 0;
            REP(j, 8) {
                if (s[i] == L[j])
                    a = j;
            }
            if (s[n - 1 - i] != R[a])
                e = false;
        }

        if (!e)
            continue;

        ans = std::max(ans, n);
    }
    cout << ans << endl;
    return 0;
}