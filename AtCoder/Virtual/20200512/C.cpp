#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
pll A[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    pll s, e;
    cin >> s.first >> s.second >> e.first >> e.second;
    ll T, V;
    cin >> T >> V;
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    REP(i, N) {
        double d = sqrt(pow(s.first - A[i].first, 2) + pow(s.second - A[i].second, 2)) +
                   sqrt(pow(A[i].first - e.first, 2) + pow(A[i].second - e.second, 2));
        if (d <= T * V) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}