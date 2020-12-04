#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool check(string s) {
    ll N = s.length();
    REP(i, N) {
        if (s[i] != s[N - 1 - i])
            return false;
    }

    REP(i, (N - 1) / 2) {
        if (s[i] != s[(N - 1) / 2 - 1 - i])
            return false;
    }

    ll cnt = 0;
    FOR(i, N, (N + 3) / 2 - 1) {
        if (s[i] != s[N - 1 - cnt++])
            return false;
    }

    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    if (check(S))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}