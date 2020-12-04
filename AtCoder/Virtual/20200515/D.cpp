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
    ll N, M;
    cin >> N >> M;
    ll n = 1;
    vector<ll> v;
    while (n * n <= M) {
        if (M % n == 0) {
            v.push_back(n);
            v.push_back(M / n);
        }
        n++;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    v.push_back(INF);
    REP(i, v.size()) {
        if (v[i] * N > M) {
            cout << v[i - 1] << endl;
            break;
        }
    }
    return 0;
}