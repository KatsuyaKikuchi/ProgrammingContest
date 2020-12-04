#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[100005];

int main() {
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    memset(T, 0, sizeof(T));
    FOR(i, N, 1) {
        if (S[i] == 'C' && S[i - 1] == 'A')
            T[i + 1]++;
    }
    REP(i, N) {
        T[i + 1] += T[i];
    }

    REP(i, Q) {
        ll l, r;
        cin >> l >> r;
        ll s = T[r] - T[l - 1];
        if (S[l - 2] == 'A' && S[l - 1] == 'C')
            s--;
        cout << s << endl;
    }

    return 0;
}