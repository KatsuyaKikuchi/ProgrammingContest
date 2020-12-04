#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[500005];

int main() {
    string S;
    cin >> S;
    ll N = S.length();
    memset(A, 0, sizeof(A));
    ll t = 0;
    REP(i, N) {
        A[i] = t;
        if (S[i] == '<')
            t++;
        else
            t = 0;
    }
    A[N] = t;
    t = 0;
    for (ll i = N; i > 0; --i) {
        A[i] = std::max(A[i], t);
        if (S[i - 1] == '>')
            t++;
        else
            t = 0;
    }
    A[0] = std::max(t, A[0]);

    ll ans = 0;
    REP(i, N + 1) {
        ans += A[i];
    }
    cout << ans << endl;

    return 0;
}