#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool test(ll n) {
    vector<ll> t, s;
    ll m = n;
    while (n > 0) {
        t.push_back(n % 10);
        n /= 10;
    }
    while (m > 0) {
        s.push_back(m % 8);
        m /= 8;
    }

    REP(i, t.size()) {
        if (t[i] == 7)
            return false;
    }
    REP(i, s.size()) {
        if (s[i] == 7)
            return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll ans = 0;
    REP(i, N) {
        if (test(i + 1))
            ans++;
    }
    cout << ans << endl;
    return 0;
}