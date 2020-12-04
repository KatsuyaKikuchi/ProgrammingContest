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
    ll A, B;
    cin >> A >> B;

    vector<ll> t;
    for (ll i = 2; i * i <= A; ++i) {
        if (A % i != 0)
            continue;
        t.push_back(i);
        while (A % i == 0)
            A /= i;
    }
    if (A > 1)
        t.push_back(A);

    vector<ll> v;
    REP(i, t.size()) {
        if (B % t[i] == 0)
            v.push_back(t[i]);
    }
    cout << v.size() + 1 << endl;

    return 0;
}