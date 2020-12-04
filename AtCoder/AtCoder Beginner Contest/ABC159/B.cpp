#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool check(string S) {
    ll N = S.length();
    REP(i, N) {
        if (S[i] != S[N - 1 - i])
            return false;
    }

    ll n = (N - 1) / 2;
    REP(i, n) {
        if (S[i] != S[n - 1 - i])
            return false;
    }

    ll m = (N + 3) / 2;
    for (ll i = m - 1; i < N; ++i) {
        if (S[i] != S[N - 1 - i])
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