#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A(N);
    ll s = 0;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        s += A[i].first;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return 2 * a.first + a.second > 2 * b.first + b.second; });
    ll s0 = 0;
    REP(i, N) {
        s0 += A[i].second + A[i].first;
        s -= A[i].first;
        if (s0 > s) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}