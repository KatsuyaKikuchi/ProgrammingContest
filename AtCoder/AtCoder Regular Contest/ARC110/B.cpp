#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e10;
ll N;
string S;

ll solve() {
    if (N == 1) {
        ll ans = 0;
        if (S[0] == '1') {
            ans = INF * 2LL;
        }
        else {
            ans = INF;
        }
        return ans;
    }
    if (N == 2) {
        ll ans = 0;
        if (S[0] == '1') {
            ans = INF;
        }
        else {
            if (S[1] == '1') {
                ans = INF - 1LL;
            }
        }
        return ans;
    }

    ll index = 0;
    if (S[0] == '1') {
        if (S[1] == '1')
            index = 0;
        else
            index = 2;
    }
    else {
        index = 1;
    }

    FOR(i, N, index) {
        ll p = i - index;
        if (p % 3 == 0 && S[i] == '0')
            return 0;
        if (p % 3 == 1 && S[i] == '0')
            return 0;
        if (p % 3 == 2 && S[i] == '1')
            return 0;
    }
    ll ret = 0;
    {
        ll p = N - index;
        ret = (p + 2) / 3;
        if (index > 0)
            ret++;
    }
    return INF - ret + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    cin >> S;

    cout << solve() << endl;
    return 0;
}