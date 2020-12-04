#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 30000;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    if (N == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }
    vector<ll> v;
    v.push_back(2);
    v.push_back(4);
    {
        ll x = 3;
        while (v.size() + 2 <= N && x + 6 <= MAX) {
            v.push_back(x);
            v.push_back(x + 6);
            x += 12;
        }
    }
    {
        ll x = 8;
        while (v.size() + 2 <= N && x + 2 <= MAX) {
            v.push_back(x);
            v.push_back(x + 2);
            x += 6;
        }
    }
    {
        ll x = 6;
        while (v.size() < N) {
            v.push_back(x);
            x += 6;
        }
    }
    sort(v.begin(), v.end());
    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}