#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, L;
    cin >> N >> L;
    getline(cin, S[0]);
    REP(i, L + 1) {
        getline(cin, S[i]);
    }
    ll n = 0;
    REP(i, S[L].length()) {
        if (S[L][i] == 'o')
            n = i;
    }

    for (ll i = L - 1; i >= 0; --i) {
        if (n - 1 >= 0 && S[i][n - 1] == '-')
            n -= 2;
        else if (n + 1 < S[i].length() && S[i][n + 1] == '-')
            n += 2;
    }
    cout << n / 2 + 1 << endl;
    return 0;
}