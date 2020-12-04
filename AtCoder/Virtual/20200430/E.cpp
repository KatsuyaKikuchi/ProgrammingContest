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
    ll n = 1;
    while (n * (n + 1) <= 2 * N) {
        if (n * (n + 1) != 2 * N) {
            n++;
            continue;
        }
        cout << "Yes" << endl;
        vector<vector<ll>> v(n + 1);
        ll index = 0;
        ll m = 1;
        REP(i, N) {
            v[index].push_back(i + 1);
            v[index + m++].push_back(i + 1);

            if (v[index].size() == n) {
                index++;
                m = 1;
            }
        }

        cout << v.size() << endl;
        REP(i, v.size()) {
            cout << v[i].size();
            REP(j, v[i].size()) {
                cout << " " << v[i][j];
            }
            cout << endl;
        }
        return 0;
    }
    cout << "No" << endl;
    return 0;
}