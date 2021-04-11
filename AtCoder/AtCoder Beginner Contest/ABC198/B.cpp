#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    ll last = N - 1;
    for (ll i = N - 1; i >= 0; --i) {
        if (S[i] != '0')
            break;
        last = i - 1;
    }

    bool enable = true;
    REP(i, N) {
        if (last - i < 0)
            break;
        if (S[i] == S[last - i])
            continue;
        enable = false;
    }
    if (enable)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}