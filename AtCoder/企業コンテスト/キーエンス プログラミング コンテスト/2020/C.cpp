#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e9;

int main() {
    ll N, K, S;
    cin >> N >> K >> S;
    vector<ll> v;
    REP(i, K) {
        v.push_back(S);
    }

    while (v.size() < N) {
        ll p = INF;
        if (S == p)
            p--;
        v.push_back(p);
    }
    REP(i, N) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}