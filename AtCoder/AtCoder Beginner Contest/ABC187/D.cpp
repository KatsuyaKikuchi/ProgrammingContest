#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll s = 0;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        s += A[i].first;
    }
    sort(A, A + N, [](pll a, pll b) { return 2 * a.first + a.second > 2 * b.first + b.second; });
    ll t = 0;
    REP(i, N) {
        ll x = A[i].second + A[i].first;
        t += x;
        s -= A[i].first;
        //cout << s << " " << t << endl;
        if (t > s) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << N << endl;
    return 0;
}