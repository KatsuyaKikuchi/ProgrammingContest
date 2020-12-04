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
    ll num = 10;
    while (true) {
        ll m = num;
        vector<ll> v;
        while (m > 0) {
            v.push_back(m % 10);
            m /= 10;
        }

        ll s = 0;
        ll p = 1;
        REP(i, v.size()) {
            s += p * v[i];
            p *= num;
        }

        if (s == N) {
            cout << num << endl;
            return 0;
        }
        if (s > N)
            break;
        num++;
    }
    cout << -1 << endl;
    return 0;
}