#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char A[4] = {'A', 'C', 'G', 'T'};

int main() {
    string S;
    cin >> S;
    ll ans = 0;
    ll m = 0;
    REP(i, S.length()) {
        bool e = false;
        REP(j, 4) {
            if (S[i] == A[j])
                e = true;
        }
        if (!e) {
            m = 0;
            continue;
        }
        m++;
        ans = std::max(m, ans);
    }
    cout << ans << endl;

    return 0;
}