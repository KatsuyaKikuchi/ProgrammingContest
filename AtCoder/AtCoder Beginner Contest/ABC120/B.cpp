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
    ll A, B, K;
    cin >> A >> B >> K;

    ll t = 1;
    ll ans = 0;
    vector<ll> v;
    while (true) {
        if (A % t == 0 && B % t == 0) {
            v.push_back(t);
        }
        t++;
        if (t > A || t > B)
            break;
    }

    cout << v[v.size() - K] << endl;
    return 0;
}