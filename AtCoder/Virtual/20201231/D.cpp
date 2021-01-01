#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll SA[100005], SB[100005];
ll TA[100005], TB[100005];

bool solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll sa = SA[b] - SA[a - 1];
    ll sb = SB[b] - SB[a - 1];
    ll ta = TA[d] - TA[c - 1];
    ll tb = TB[d] - TB[c - 1];

    ll diff = abs((sa + sb * 2) - (ta + tb * 2));
    return diff % 3 == 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    memset(SA, 0, sizeof(SA));
    memset(SB, 0, sizeof(SB));
    memset(TA, 0, sizeof(TA));
    memset(TB, 0, sizeof(TB));
    REP(i, S.length()) {
        if (S[i] == 'A')
            SA[i + 1]++;
        else
            SB[i + 1]++;
        SA[i + 1] += SA[i];
        SB[i + 1] += SB[i];
    }
    REP(i, T.length()) {
        if (T[i] == 'A')
            TA[i + 1]++;
        else
            TB[i + 1]++;
        TA[i + 1] += TA[i];
        TB[i + 1] += TB[i];
    }

    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}