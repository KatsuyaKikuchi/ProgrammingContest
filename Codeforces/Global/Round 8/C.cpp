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
    vector<pll> v;
    REP(i, 2 * N + 1) {
        v.push_back(pll(2, i));
    }
    REP(i, N) {
        v.push_back(pll(1, 2 * i + 1));
        v.push_back(pll(3, 2 * i + 1));
    }
    v.push_back(pll(1, 0));
    if (N % 2 == 0)
        v.push_back(pll(1, 2 * N));
    else
        v.push_back(pll(3, 2 * N));

    {
        ll index = 1;
        while (index < 2 * N - 1) {
            v.push_back(pll(4, index));
            v.push_back(pll(4, index + 1));
            v.push_back(pll(4, index + 2));
            index += 4;
        }
    }
    {
        ll index = 3;
        while (index < 2 * N - 1) {
            v.push_back(pll(0, index));
            v.push_back(pll(0, index + 1));
            v.push_back(pll(0, index + 2));
            index += 4;
        }
    }

    cout << v.size() << endl;
    REP(i, v.size()) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}