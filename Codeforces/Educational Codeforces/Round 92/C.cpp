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
    ll ans = N;
    REP(i, 10) {
        ll n = 0;
        REP(j, N) {
            if (S[j] - '0' == i)
                n++;
        }
        ans = std::min(N - n, ans);
    }
    REP(a, 10) {
        REP(b, 10) {
            ll n = 0;
            REP(i, N) {
                ll x = S[i] - '0';
                if (n % 2 == 0 && x == a)
                    n++;
                else if (n % 2 == 1 && x == b)
                    n++;
            }
            n = n - (n % 2);
            ans = std::min(ans, N - n);
        }
    }

    return ans;
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