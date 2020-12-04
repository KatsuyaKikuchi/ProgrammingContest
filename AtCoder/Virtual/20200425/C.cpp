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
    ll sum = 0;
    REP(i, N) {
        sum += i + 1;
        if (sum >= N) {
            vector<ll> v;
            for (ll j = i + 1; j > 0; --j) {
                if (j <= N) {
                    v.push_back(j);
                    N -= j;
                }
            }

            REP(j, v.size()) {
                cout << v[j] << endl;
            }
            break;
        }
    }
    return 0;
}