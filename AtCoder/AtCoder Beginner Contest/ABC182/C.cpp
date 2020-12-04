#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> v;
    ll n = N;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    ll sum = 0;
    REP(i, v.size()) {
        sum += v[i];
    }

    if (sum % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll a = 0, b = 0;
    REP(i, v.size()) {
        if (v[i] % 3 == 1)
            a++;
        else if (v[i] % 3 == 2)
            b++;
    }
    if (sum % 3 == 1) {

        if (a > 0 && v.size() > 1)
            cout << 1 << endl;
        else if (b > 1 && v.size() > 2)
            cout << 2 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    else {
        if (b > 0 && v.size() > 1)
            cout << 1 << endl;
        else if (a > 1 && v.size() > 2)
            cout << 2 << endl;
        else
            cout << -1 << endl;
        return 0;

    }
    return 0;
}