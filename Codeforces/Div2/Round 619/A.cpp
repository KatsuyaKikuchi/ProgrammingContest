#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool check(string a, string b, string c) {
    ll n = a.length();
    REP(i, n) {
        if (c[i] == a[i] || c[i] == b[i])
            continue;
        return false;
    }
    return true;
}

int main() {
    ll N;
    cin >> N;
    REP(_, N) {
        string a, b, c;
        cin >> a >> b >> c;
        if (check(a, b, c))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}