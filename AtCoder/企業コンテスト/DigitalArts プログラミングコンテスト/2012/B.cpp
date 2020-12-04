#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[25];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll s = 0;
    ll N = S.length();
    REP(i, N) {
        s += S[i] - 'a' + 1;
    }
    if (s == 26 * 20 || s == 1) {
        cout << "NO" << endl;
        return 0;
    }

    REP(i, 20) {
        T[i] = -1;
    }

    ll mi = 0;
    REP(i, N) {
        T[i] = S[i] - 'a';
        if (S[i] >= S[mi])
            mi = i;
    }
    T[mi]--;
    ll d = 1;
    REP(i, 20) {
        if (i == mi || T[i] + d >= 26)
            continue;
        T[i] = (T[i] + d) % 26;
        break;
    }

    REP(i, 20) {
        if (T[i] < 0)
            continue;
        cout << (char) ('a' + T[i]);
    }
    cout << endl;

    return 0;
}