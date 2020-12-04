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
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    REP(i, N) {
        if (S[i] == T[i])
            continue;
        char s = S[i];
        char t = T[i];
        if (s >= '0' && s <= '9') {
            REP(j, N) {
                if (S[j] == t)
                    S[j] = s;
                if (T[j] == t)
                    T[j] = s;
            }
        }
        else {
            REP(j, N) {
                if (S[j] == s)
                    S[j] = t;
                if (T[j] == s)
                    T[j] = t;
            }
        }
    }

    ll ans = 1;
    REP(i, N) {
        char s = S[i];
        if (s >= '0' && s <= '9')
            continue;
        if (i == 0)
            ans *= 9LL;
        else
            ans *= 10LL;
        REP(j, N) {
            if (S[j] == s)
                S[j] = '1';
        }
    }
    cout << ans << endl;
    return 0;
}