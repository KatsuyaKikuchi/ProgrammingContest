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
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i != 0)
            continue;
        v.push_back(i);
        ll t = N / i;
        if (i != t)
            v.push_back(t);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    REP(i, v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}